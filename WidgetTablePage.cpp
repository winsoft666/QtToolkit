#include "WidgetTablePage.h"
#include "QtToolkit/DSLLayout.hpp"
#include <QApplication>
#include <QThread>
#include <QDebug>
#include <QDateTime>
#include <QMutex>
#include <QWaitCondition>

CustomWidget::CustomWidget(int idx, QWidget* parent /*= Q_NULLPTR*/) :
    QPushButton(parent) {
    setupUi();

    lblName_->setText(QString("PUBG %1").arg(idx));

    setStyleSheet(
        u8R"(
#CustomWidget {
    border: none;
}

#lblName {
    font-size: 12px;
    color: #000000;
}

#lblImg {
    image: url(:/Sample/image/pubg.png);
}
)");

    setFixedSize(307, 167);
}

QString CustomWidget::name() const {
    return lblName_->text();
}

void CustomWidget::setupUi() {
    using namespace tk;

    setObjectName("CustomWidget");
    lblImg_ = new QLabel();
    lblImg_->setObjectName("lblImg");
    lblImg_->setFixedSize(307, 145);

    lblName_ = new QLabel();
    lblName_->setObjectName("lblName");
    lblName_->setFixedHeight(22);
    lblName_->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    auto layout = ZeroVBox(
        lblImg_,
        lblName_,
        Stretch());
    setLayout(layout);
}

WidgetTablePage::WidgetTablePage(QWidget* parent /*= Q_NULLPTR*/) :
    QWidget(parent) {
    toast_ = new tk::ToastWidget(this);

    pagination_ = new tk::PaginationWidget();
    connect(pagination_, &tk::PaginationWidget::currentPageChanged, this, [this](int pageNum) {
        fillupData(pageNum);
    });

    table_ = new tk::WidgetTable();
    table_->setObjectName("table");
    table_->setSpacing(10, 10);
    table_->setContentsMargins(0, 0, 0, 0);
    table_->setColumnCount(3);
    //table_->setCellCountHintChangedNoitfyEnabled(true, QSize(307, 167));
    table_->setStyleSheet(
        u8R"(
#table {
    border: 1px solid #cccccc;
}
)");

    connect(table_, &tk::WidgetTable::cellCountHintChanged, this, [this](int rowCount, int colCount) {
        const int itemPerPage = rowPerPage_ * colCount;
        int pageCount = itemCount_ / itemPerPage;
        if (itemCount_ % itemPerPage != 0)
            pageCount++;

        pagination_->setTotalPage(pageCount);
        pagination_->setCurrentPage(0);

        table_->setColumnCount(colCount);
        fillupData(0);
    });

    spinItemCount_ = new QSpinBox();
    spinItemCount_->setRange(0, 65535);
    spinItemCount_->setValue(2000);

    spinRowPerPage_ = new QSpinBox();
    spinRowPerPage_->setRange(0, 65535);
    spinRowPerPage_->setValue(20);

    spinColPerPage_ = new QSpinBox();
    spinColPerPage_->setRange(0, 65535);
    spinColPerPage_->setValue(6);

    btnApply_ = new QPushButton("Apply");
    connect(btnApply_, &QPushButton::clicked, this, [this]() {
        itemCount_ = spinItemCount_->value();
        rowPerPage_ = spinRowPerPage_->value();
        colPerPage_ = spinColPerPage_->value();

        if (itemCount_ <= 0 || rowPerPage_ <= 0 || colPerPage_ <= 0)
            return;

        const int itemPerPage = rowPerPage_ * colPerPage_;
        int pageCount = itemCount_ / itemPerPage;
        if (itemCount_ % itemPerPage != 0)
            pageCount++;

        pagination_->setTotalPage(pageCount);
        pagination_->setCurrentPage(0);

        table_->setColumnCount(colPerPage_);

        fillupData(0);
    });

    setLayout(tk::VBoxEx(
        table_,
        pagination_,
        tk::HBox(
            new QLabel("Total:"),
            spinItemCount_,
            tk::Spacing(20),
            new QLabel("Row:"),
            spinRowPerPage_,
            tk::Spacing(20),
            new QLabel("Column:"),
            spinColPerPage_,
            tk::Spacing(20),
            btnApply_,
            tk::Stretch())));
}

void WidgetTablePage::fillupData(int pageNum) {
    table_->removeAll();

    QThread* t = QThread::create([this, pageNum]() {
        QDateTime dt = QDateTime::currentDateTime();

        table_->beginBatchAppend();
        QWaitCondition cond;
        QMutex mutex;
        const int itemPerPage = rowPerPage_ * colPerPage_;
        for (int i = 0; i < itemPerPage; i++) {
            int idx = pageNum * itemPerPage + i;
            if (idx == itemCount_)
                break;

            qDebug() << "Begin" << idx;
            QMetaObject::invokeMethod(this, [this, idx, &cond]() {
                CustomWidget* w = new CustomWidget(idx);
                connect(w, &QPushButton::clicked, this, [w, this]() {
                    toast_->setText(w->name());
                    toast_->show();
                });
                table_->appendWidget(w);
                qDebug() << "Inserted" << idx;
                cond.notify_all();
            });
            qDebug() << "End" << idx;

            mutex.lock();
            cond.wait(&mutex);
            mutex.unlock();
            QThread::currentThread()->msleep(1000);
        }

        QMetaObject::invokeMethod(this, [this]() {
            table_->endBatchAppend();
        });
        qDebug() << "Insert finished:" << (QDateTime::currentMSecsSinceEpoch() - dt.toMSecsSinceEpoch()) << "ms";
    });
    t->start();
}

#include "PaginationPage.h"
#include "QtToolkit/DSLLayout.hpp"

PaginationPage::PaginationPage(QWidget* parent /*= Q_NULLPTR*/) :
    QWidget(parent) {
    toast_ = new tk::ToastWidget(this);

    pagination1_ = new tk::PaginationWidget();
    connect(pagination1_, &tk::PaginationWidget::currentPageChanged, this, [this](int pageNum) {
        toast_->setText(QString("Goto page %1").arg(pageNum));
        toast_->show();
    });
    pagination1_->setTotalPage(1);
    pagination1_->setCurrentPage(0);
    pagination1_->setPageButtonStyleSheet("color: #0000ff;", "color: #ff0000;");

    pageNumSlider_ = new QSlider(Qt::Orientation::Horizontal);
    pageNumSlider_->setRange(0, 100);
    connect(pageNumSlider_, &QSlider::valueChanged, this, [this](int value) {
        lblPageNum_->setText(QString::number(value));
        pagination1_->setTotalPage(value);
    });

    lblPageNum_ = new QLabel();

    setLayout(tk::VBoxEx(
        tk::Spacing(10),
        pagination1_,
        tk::Stretch(),
        tk::HBox(new QLabel("Page Count:"), pageNumSlider_, lblPageNum_),
        tk::Spacing(10)));
}

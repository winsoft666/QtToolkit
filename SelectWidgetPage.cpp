#include "SelectWidgetPage.h"
#include "QtToolkit/WidgetCreator.h"

SelectWidgetPage::SelectWidgetPage(QWidget* parent /*= Q_NULLPTR*/) :
    QWidget(parent) {
    setupUi();

    tk::SelectableWidget* selectWidget1 = new tk::SelectableWidget(this);
    selectWidget1->setWidget(lbl1_);
    selectWidget1->setDrawPoint(true);

    tk::SelectableWidget* selectWidget2 = new tk::SelectableWidget(this);
    selectWidget2->setWidget(lbl2_);
    selectWidget2->setPointStyle(tk::SelectableWidget::PointStyle::PS_Circle);
    selectWidget2->setPointColor(QColor(255, 0, 0));
    connect(selectWidget2, &tk::SelectableWidget::widgetPressed, this, [this](QWidget* widget) {
        tk::SelectableWidget* selectWidget = dynamic_cast<tk::SelectableWidget*>(sender());
        if (selectWidget) {
            selectWidget->setDrawPoint(true);
        }
    });
    connect(selectWidget2, &tk::SelectableWidget::widgetRelease, this, [this](QWidget* widget) {
        tk::SelectableWidget* selectWidget = dynamic_cast<tk::SelectableWidget*>(sender());
        if (selectWidget) {
            //selectWidget->setDrawPoint(false);
        }
    });

    tk::SelectableWidget* selectWidget3 = new tk::SelectableWidget(this);
    selectWidget3->setWidget(btn_);
    selectWidget3->setDrawPoint(true);
}

void SelectWidgetPage::setupUi() {
    lbl1_ = new QLabel(this);
    lbl1_->setStyleSheet("image: url(:/Sample/image/gril.png);");
    lbl1_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lbl1_->resize(200, 200);
    lbl1_->move(100, 100);

    lbl2_ = new QLabel(this);
    lbl2_->setStyleSheet("image: url(:/Sample/image/gril.png);");
    lbl2_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lbl2_->resize(200,200);
    lbl2_->move(320, 100);

    btn_ = new QPushButton("test button", this);
    btn_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn_->resize(200, 200);
    btn_->move(200, 320);
}

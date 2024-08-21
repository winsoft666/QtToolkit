#include "ClockPage.h"
#include "QtToolkit/WidgetCreator.h"

ClockPage::ClockPage(QWidget* parent /*= Q_NULLPTR*/) :
    QWidget(parent) {
    clock1_ = new tk::ClockWidget();
    clock1_->resize(100, 100);

    clock2_ = new tk::ClockWidget();
    clock2_->resize(200, 200);
    clock2_->setSecondStyle(tk::ClockWidget::SecondStyle::SS_Spring);

    clock3_ = new tk::ClockWidget();
    clock3_->resize(300, 300);
    clock3_->setSecondStyle(tk::ClockWidget::SecondStyle::SS_Continue);

    clock4_ = new tk::ClockWidget();
    clock4_->resize(300, 300);
    clock4_->setSecondStyle(tk::ClockWidget::SecondStyle::SS_Hide);

    QHBoxLayout* h = tk::CreateHLayout(20);
    {
        h->addWidget(clock1_);
        h->addWidget(clock2_);
        h->addWidget(clock3_);
        h->addWidget(clock4_);
    }

    QVBoxLayout* v = tk::CreateVLayout();
    v->addStretch(1);
    v->addLayout(h, 1);
    v->addStretch(1);

    setLayout(v);
}

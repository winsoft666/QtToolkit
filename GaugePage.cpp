#include "GaugePage.h"
#include "QtToolkit/DSLLayout.hpp"
#include <QTimer>

GaugePage::GaugePage(QWidget* parent /*= Q_NULLPTR*/) :
    QWidget(parent) {
    slider_ = new QSlider(Qt::Horizontal);
    slider_->setRange(0, 100);

    connect(slider_, &QSlider::valueChanged, this, [this](int value) {
        guage_->setCurrentValue(value);
    });

    guage_ = new tk::GaugeWidget();
    guage_->setMinValue(0.0);
    guage_->setMaxValue(100.0);

    setLayout(tk::VBoxEx(
        tk::HBoxEx(
            guage_)
            .setSpacing(6),
        slider_,
        tk::Spacing(10)));

    QTimer* t = new QTimer(this);
    connect(t, &QTimer::timeout, this, [this]() {
        if (guage_->currentValue() == guage_->maxValue())
            guage_->setCurrentValue(guage_->minValue());
        else
            guage_->setCurrentValue(guage_->currentValue() + 1);
    });
    t->setInterval(300);
    t->start();
}

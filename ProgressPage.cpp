#include "ProgressPage.h"
#include "QtToolkit/DSLLayout.hpp"
#include <atomic>

ProgressPage::ProgressPage(QWidget* parent /*= Q_NULLPTR*/) :
    QWidget(parent) {
    slider_ = new QSlider(Qt::Horizontal);
    slider_->setRange(0, 100);

    taichiProgress_ = new tk::TaiChiProgress(-1, -1);
    taichiProgress_->setFixedSize(160, 160);

    taichiProgress2_ = new tk::TaiChiProgress(0, 100);
    taichiProgress2_->setFixedSize(160, 160);
    taichiProgress2_->setCurrentValue(0);

    circularProgress_ = new tk::CircularProgress();
    circularProgress_->setCircularColor(QColor(225, 102, 255));
    circularProgress_->setTextColor(QColor(225, 102, 255));
    circularProgress_->setFixedSize(160, 160);
    circularProgress_->setCurrentValue(5);

    circularProgress2_ = new tk::CircularProgress();
    circularProgress2_->setCircularColor(QColor(225, 102, 255));
    circularProgress2_->setTextColor(QColor(225, 102, 255));
    circularProgress2_->setFixedSize(160, 160);
    circularProgress2_->setMaxValue(10);
    circularProgress2_->setCurrentValue(0);

    waitingProgress_ = new tk::WaitingProgress();
    waitingProgress_->setBarColor(QColor(225, 102, 255));
    waitingProgress_->setFixedSize(100, 60);

    curveProgress_ = new tk::CurveProgress();
    curveProgress_->setFixedSize(160, 160);

    curveProgress2_ = new tk::CurveProgress();
    curveProgress2_->setFixedSize(160, 160);
    curveProgress2_->setMinValue(0);
    curveProgress2_->setMaxValue(100);

    arcProgress_ = new tk::ArcProgress();
    arcProgress_->setFixedSize(160, 160);

    arcProgress2_ = new tk::ArcProgress();
    arcProgress2_->setFixedSize(160, 160);
    arcProgress2_->setMinValue(0);
    arcProgress2_->setMaxValue(100);

    auto layout = tk::VBox(
        tk::HBox(
            taichiProgress_,
            taichiProgress2_,
            circularProgress_,
            circularProgress2_,
            tk::Stretch()),
        tk::HBox(
            waitingProgress_,
            tk::Stretch()),
        tk::HBox(
            curveProgress_,
            curveProgress2_,
            arcProgress_,
            arcProgress2_,
            tk::Stretch()),
        tk::Stretch(),
        slider_,
        tk::Spacing(20));

    setLayout(layout);

    connect(slider_, &QSlider::valueChanged, this, [this](int value) {
        taichiProgress2_->setCurrentValue(value);
        circularProgress2_->setCurrentValue(value / 100.0 * (circularProgress2_->maxValue() - circularProgress2_->minValue()) + circularProgress2_->minValue());
        curveProgress2_->setCurrentValue(value / 100.0 * (curveProgress2_->maxValue() - curveProgress2_->minValue()) + curveProgress2_->minValue());
        arcProgress2_->setCurrentValue(value / 100.0 * (arcProgress2_->maxValue() - arcProgress2_->minValue()) + arcProgress2_->minValue());
    });

    std::atomic<int> a;
}

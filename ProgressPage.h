#pragma once
#include "QtToolkit/ClockWidget.h"
#include "QtToolkit/TaiChiProgress.h"
#include "QtToolkit/CircularProgress.h"
#include "QtToolkit/WaitingProgress.h"
#include "QtToolkit/CurveProgress.h"
#include "QtToolkit/ArcProgress.h"
#include <QSlider>

class EightDiagramsProgressWidget;
class ProgressPage : public QWidget {
    Q_OBJECT
   public:
    ProgressPage(QWidget* parent = Q_NULLPTR);

   private:
    QSlider* slider_ = Q_NULLPTR;

    tk::TaiChiProgress* taichiProgress_ = Q_NULLPTR;
    tk::TaiChiProgress* taichiProgress2_ = Q_NULLPTR;

    tk::CircularProgress* circularProgress_ = Q_NULLPTR;
    tk::CircularProgress* circularProgress2_ = Q_NULLPTR;

    tk::CurveProgress* curveProgress_ = Q_NULLPTR;
    tk::CurveProgress* curveProgress2_ = Q_NULLPTR;

    tk::ArcProgress* arcProgress_ = Q_NULLPTR;
    tk::ArcProgress* arcProgress2_ = Q_NULLPTR;

    tk::WaitingProgress* waitingProgress_ = Q_NULLPTR;
};
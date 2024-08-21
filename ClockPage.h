#pragma once
#include "QtToolkit/ClockWidget.h"

class ClockPage : public QWidget {
    Q_OBJECT
   public:
    ClockPage(QWidget* parent = Q_NULLPTR);

   private:
    tk::ClockWidget* clock1_ = Q_NULLPTR;
    tk::ClockWidget* clock2_ = Q_NULLPTR;
    tk::ClockWidget* clock3_ = Q_NULLPTR;
    tk::ClockWidget* clock4_ = Q_NULLPTR;
};
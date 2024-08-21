#pragma once
#include "QtToolkit/StuffLabel.h"

class StuffLabelPage : public QWidget {
    Q_OBJECT
   public:
    StuffLabelPage(QWidget* parent = Q_NULLPTR);

   private:
    tk::StuffLabel* stuffLabel1_ = Q_NULLPTR;
    tk::StuffLabel* stuffLabel2_ = Q_NULLPTR;
    tk::StuffLabel* stuffLabel3_ = Q_NULLPTR;
    tk::StuffLabel* stuffLabel4_ = Q_NULLPTR;
};
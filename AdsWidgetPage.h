#pragma once
#include "QtToolkit/AdsWidget.h"

class AdsWidgetPage : public QWidget {
    Q_OBJECT
   public:
    AdsWidgetPage(QWidget* parent = Q_NULLPTR);

   private:
    tk::AdsWidget* adsWidget_ = Q_NULLPTR;
};
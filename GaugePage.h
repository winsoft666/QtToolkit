#pragma once
#include "QtToolkit/GaugeWidget.h"
#include <QSlider>

class GaugePage : public QWidget {
    Q_OBJECT
   public:
    GaugePage(QWidget* parent = Q_NULLPTR);

   private:
    tk::GaugeWidget* guage_ = Q_NULLPTR;
    QSlider* slider_ = nullptr;
};

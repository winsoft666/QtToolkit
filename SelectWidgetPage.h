#pragma once
#include "QtToolkit/SelectableWidget.h"
#include <QLabel>
#include <QPushButton>

class SelectWidgetPage : public QWidget {
    Q_OBJECT
   public:
    SelectWidgetPage(QWidget* parent = Q_NULLPTR);

   private:
    void setupUi();

   private:
    QLabel* lbl1_ = Q_NULLPTR;
    QLabel* lbl2_ = Q_NULLPTR;
    QPushButton* btn_ = Q_NULLPTR;
};
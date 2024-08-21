#pragma once
#include "QtToolkit/PaginationWidget.h"
#include "QtToolkit/ToastWidget.h"
#include <QSlider>

class PaginationPage : public QWidget {
    Q_OBJECT
   public:
    PaginationPage(QWidget* parent = Q_NULLPTR);

   private:
    tk::ToastWidget* toast_ = Q_NULLPTR;
    QSlider* pageNumSlider_ = Q_NULLPTR;
    QLabel* lblPageNum_ = Q_NULLPTR;
    tk::PaginationWidget* pagination1_ = Q_NULLPTR;
};

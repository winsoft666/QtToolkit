#pragma once
#include "QtToolkit/PaginationWidget.h"
#include "QtToolkit/WidgetTable.h"
#include "QtToolkit/ToastWidget.h"
#include <QSpinBox>

class CustomWidget : public QPushButton {
    Q_OBJECT
   public:
    CustomWidget(int idx, QWidget* parent = Q_NULLPTR);

    QString name() const;

   protected:
    void setupUi();

   protected:
    QWidget* centralWidget_ = Q_NULLPTR;
    QLabel* lblImg_ = Q_NULLPTR;
    QLabel* lblName_ = Q_NULLPTR;
};

class WidgetTablePage : public QWidget {
    Q_OBJECT
   public:
    WidgetTablePage(QWidget* parent = Q_NULLPTR);

   protected:
    void fillupData(int pageNum);

   private:
    tk::ToastWidget* toast_ = Q_NULLPTR;
    tk::PaginationWidget* pagination_ = Q_NULLPTR;
    tk::WidgetTable* table_ = Q_NULLPTR;

    int itemCount_ = 0;
    int rowPerPage_ = 0;
    int colPerPage_ = 0;
    
    QSpinBox* spinItemCount_ = Q_NULLPTR;
    QSpinBox* spinRowPerPage_ = Q_NULLPTR;
    QSpinBox* spinColPerPage_ = Q_NULLPTR;
    QPushButton* btnApply_ = Q_NULLPTR;
};

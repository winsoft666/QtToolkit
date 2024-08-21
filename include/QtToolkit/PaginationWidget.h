#ifndef TK_PAGINATION_WIDGET_H_
#define TK_PAGINATION_WIDGET_H_
#pragma once

#include "QtToolkit/TKGlobal.h"
#include <QVector>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

namespace tk {
class TK_API PaginationWidget : public QWidget {
    Q_OBJECT
   public:
    PaginationWidget(int middlePageButtonCount = 5, QWidget* parent = Q_NULLPTR);

   public Q_SLOTS:
    void setTotalPage(int num);
    void setCurrentPage(int idx);
    void setPageButtonSize(int s);

    void setPageButtonStyleSheet(const QString& normal, const QString& checked);
    void setMoreLabelStyleSheet(const QString& qss);
    void setPreviousPageButtonStyleSheet(const QString& qss);
    void setNextPageButtonStyleSheet(const QString& qss);
   signals:
    void currentPageChanged(int page);

   public:
    int totalPage() const;
    int currentPage() const;
    int pageButtonSize() const;

   protected Q_SLOTS:
    void updateLayout(bool pageBtnSizeChanged);
    void onPageButtonClicked();
    void onGotoPreviousClicked();
    void onGotoNextClicked();

    void updateQSS();

   protected:
    int totalPage_ = 0;
    int curPage_ = -1;
    int pageButtonSize_ = 30;
    int middlePageBtnNum_ = 5;

    QPushButton* btnFirstPage_ = Q_NULLPTR;
    QPushButton* btnLastPage_ = Q_NULLPTR;
    QPushButton* btnGotoPrevious_ = Q_NULLPTR;
    QPushButton* btnGotoNext_ = Q_NULLPTR;
    QLabel* lblMoreLeft_ = Q_NULLPTR;
    QLabel* lblMoreRight_ = Q_NULLPTR;

    QVector<QPushButton*> middlePages_;

    QHBoxLayout* layout_ = Q_NULLPTR;

    QString pageBtnNormalQSS_;
    QString pageBtnCheckedQSS_;
    QString moreLabelQSS_;
    QString previousBtnQSS_;
    QString nextBtnQSS_;
};
}  // namespace tk

#endif  // !TK_PAGINATION_WIDGET_H_

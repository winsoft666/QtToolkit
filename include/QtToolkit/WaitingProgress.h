#ifndef TK_WAITING_PROGRESS_H_
#define TK_WAITING_PROGRESS_H_
#pragma once

#include "QtToolkit/TKGlobal.h"
#include <QWidget>

class QTimer;

namespace tk {
// 三条竖线样式的等待动画
class TK_API WaitingProgress : public QWidget {
    Q_OBJECT
   public:
    WaitingProgress(QWidget* parent = Q_NULLPTR);
    ~WaitingProgress();

   public Q_SLOTS:
    void setBarColor(const QColor& c);

   public:
    QColor barColor() const;

   protected:
    void resizeEvent(QResizeEvent* e) override;
    void paintEvent(QPaintEvent* e) override;

   protected:
    qreal avaliableHeight() const;
    void calculateBarsInitHeight();
    void calculateBarHeight(qreal* curHeight, qreal barMinHeight, qreal barMaxHeight);

   protected:
    QColor barColor_ = QColor(0, 0, 0);
    QTimer* timer_ = Q_NULLPTR;
    qreal barsHeight_[3];
};
}  // namespace tk

#endif  // !TK_WAITING_PROGRESS_H_

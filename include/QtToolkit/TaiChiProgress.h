#ifndef TK_TAICHI_PROGRESS_WIDGET_H_
#define TK_TAICHI_PROGRESS_WIDGET_H_
#pragma once
#include "QtToolkit/TKGlobal.h"
#include <QWidget>

class QTimer;
namespace tk {
// Ì«¼«°ËØÔÍ¼
class TK_API TaiChiProgress : public QWidget {
    Q_OBJECT
   public:
    TaiChiProgress(QWidget* parent = Q_NULLPTR);
    TaiChiProgress(int minValue, int maxValue, QWidget* parent = Q_NULLPTR);

    bool clockWise() const;
    int maxValue() const;
    int minValue() const;
    int currentValue() const;

    QColor foregroundColor() const;
    QColor backgroundColor() const;

    int interval() const;

   public slots:
    void setClockWise(bool clockWise);
    void setMaxValue(int v);
    void setMinValue(int v);
    void setCurrentValue(int v);

    void setForegroundColor(const QColor& c);
    void setBackgroundColor(const QColor& c);

    void setInterval(int v);

   protected:
    void paintEvent(QPaintEvent* e) override;

   protected:
    bool clockWise_ = true;
    int interval_ = 100;
    int maxValue_ = 100;
    int minValue_ = 0;
    int currentValue_ = 0;
    QColor fgColor_ = QColor(0, 0, 0);
    QColor bgColor_ = QColor(255, 255, 255);
    QTimer* timer_ = Q_NULLPTR;
};
}  // namespace tk
#endif  // !TK_TAICHI_PROGRESS_WIDGET_H_

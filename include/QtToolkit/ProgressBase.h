#ifndef TK_PROGRESS_BASE_WIDGET_H_
#define TK_PROGRESS_BASE_WIDGET_H_
#pragma once

#include "QtToolkit/TKGlobal.h"
#include <QWidget>

class QTimer;
class QPainter;

namespace tk {
class TK_API ProgressBase : public QWidget {
    Q_OBJECT
   public:
    ProgressBase(QWidget* parent = Q_NULLPTR);
    virtual ~ProgressBase();

    bool clockWise() const;
    int maxValue() const;
    int minValue() const;
    int currentValue() const;

    QColor textColor() const;

    int interval() const;

   public slots:
    void setClockWise(bool clockWise);
    void setMaxValue(int v);
    void setMinValue(int v);
    void setCurrentValue(int v);

    void setTextColor(const QColor& c);

    void setInterval(int v);

   protected:
    virtual int getDefaultMaxValue() const;

   protected:
    bool clockWise_ = true;
    int interval_ = 100;
    int maxValue_ = 0;
    int minValue_ = 0;
    int currentValue_ = 0;
    QColor textColor_ = QColor(0, 0, 0);
    QTimer* timer_ = Q_NULLPTR;
};
}  // namespace tk
#endif  // !TK_PROGRESS_BASE_WIDGET_H_

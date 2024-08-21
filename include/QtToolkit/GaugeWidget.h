#ifndef TK_GAUGE_WIDGET_H_
#define TK_GAUGE_WIDGET_H_
#pragma once

#include "QtToolkit/TKGlobal.h"
#include <QWidget>

namespace tk {
class TK_API GaugeWidget : public QWidget {
    Q_OBJECT
   public:
    GaugeWidget(QWidget* parent = Q_NULLPTR);
    ~GaugeWidget();

   public Q_SLOTS:
    void setMinValue(qreal r);
    void setMaxValue(qreal r);
    void setCurrentValue(qreal r);

    // 正三点钟方向为0度，按逆时针方向增长至360度
    void setStartAngle(qreal angle);
    void setEndAngle(qreal angle);

   public:
    qreal minValue() const;
    qreal maxValue() const;
    qreal currentValue() const;

    qreal startAngle() const;
    qreal endAngle() const;

   protected:
    void paintEvent(QPaintEvent* e) override;

   protected:
    qreal minValue_ = 0.0;
    qreal maxValue_ = 100.0;
    qreal curValue_ = 0.0;

    qreal startAngle_ = -30;
    qreal endAngle_ = 210;

    int majorScaleNum_ = 10;
    int scaleNumPerMajor_ = 10;
};
}  // namespace tk

#endif  // !TK_GAUGE_WIDGET_H_

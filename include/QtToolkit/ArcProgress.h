#ifndef TK_ARC_PROGRESS_H_
#define TK_ARC_PROGRESS_H_
#pragma once

#include "QtToolkit/ProgressBase.h"

namespace tk {
class TK_API ArcProgress : public ProgressBase {
    Q_OBJECT
   public:
    ArcProgress(QWidget* parent = Q_NULLPTR);

    qreal lineWidth() const;
    QColor lineColor() const;

   public Q_SLOTS:
    void setLineWidth(qreal w);
    void setLineColor(QColor c);

   protected:
    void paintEvent(QPaintEvent* e) override;

    int getDefaultMaxValue() const override;

   protected:
    qreal lineWidth_ = 16.0;
    QColor lineColor_ = QColor(0, 240, 240);
};
}  // namespace tk
#endif

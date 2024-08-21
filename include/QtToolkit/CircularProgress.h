#ifndef TK_CIRCULAR_PROGRESS_WIDGET_H_
#define TK_CIRCULAR_PROGRESS_WIDGET_H_
#pragma once

#include "QtToolkit/ProgressBase.h"

namespace tk {
class TK_API CircularProgress : public ProgressBase {
    Q_OBJECT
   public:
    CircularProgress(QWidget* parent = Q_NULLPTR);

    QColor circularColor() const;

   public slots:
    void setCircularColor(const QColor& c);

   protected:
    void paintEvent(QPaintEvent* e) override;

    int getDefaultMaxValue() const override;

   protected:
    QColor circularColor_ = QColor(0, 0, 0);
};
}  // namespace tk
#endif  // !TK_CIRCULAR_PROGRESS_WIDGET_H_

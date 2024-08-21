#ifndef TK_LAYOUT_DEBUGGER_H_
#define TK_LAYOUT_DEBUGGER_H_
#pragma once

#include "QtToolkit/TKGlobal.h"
#include <QObject>
#include <QPoint>

class QPainter;
class QLayout;

namespace tk {
class TK_API LayoutDebugger : public QObject {
    Q_OBJECT

   public:
    explicit LayoutDebugger(QObject* parent);

   protected:
    bool eventFilter(QObject* object, QEvent* e) override;
    void timerEvent(QTimerEvent* e) override;

   protected:
    void recrusiveEventHandle(const QWidget* widget);
    void drawLayout(QPainter* painter, QLayout* layout, std::int32_t layer = 0);

   protected:
    std::int32_t timerId_ = 0;
    QPoint currentPosition_ = QPoint(-1, -1);
};
}  // namespace tk
#endif  // !TK_LAYOUT_DEBUGGER_H_

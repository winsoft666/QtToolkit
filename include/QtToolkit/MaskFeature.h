#pragma once
#include "QtToolkit/TKGlobal.h"
#include <QWidget>

namespace tk {
class TK_API MaskFeature {
   public:
    MaskFeature(QWidget* host,
                const QMargins& contentMargins,
                int borderRadius,
                QColor maskColor = QColor(0, 0, 0, 153));

   public Q_SLOTS:
    virtual void showMask();
    virtual void hideMask();

   protected:
    virtual void setupUi();

   protected:
    int showTimes_ = 0;
    int borderRadius_ = 0;
    QWidget* widget_ = nullptr;
    QWidget* host_ = nullptr;
    QMargins contentMargins_;
    QColor maskColor_;
};
}  // namespace tk
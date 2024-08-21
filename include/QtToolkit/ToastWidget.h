#pragma once
#include "QtToolkit/TKGlobal.h"
#include <QWidget>
#include <QLabel>

class QTimer;
class QPropertyAnimation;
namespace tk {
class TK_API ToastWidget : public QWidget {
    Q_OBJECT
   public:
    ToastWidget(QWidget* parent = Q_NULLPTR);
    ToastWidget(const QString& text, QWidget* parent = Q_NULLPTR);

    int displayTime() const;

    QString text() const;
    QColor textColor() const;
    QColor backgroundColor() const;
   public Q_SLOTS:
    void show();

    // 设置显示时间，不包含关闭动画时间
    void setDisplayTime(int ms);

    void setText(const QString& text);
    void setFontMargin(int x, int y);
    void setFontSize(int size);
    void setTextColor(QColor clr);
    void setBackgroundColor(QColor clr);

   protected:
    void paintEvent(QPaintEvent* e) override;

   protected:
    QString text_;
    QPropertyAnimation* hideAnimation_ = Q_NULLPTR;
    QTimer* hideTimer_ = Q_NULLPTR;
    QFont font_;
    QPoint margin_ = {16, 12};
    QColor textColor_ = QColor(255, 255, 255);
    QColor backgroundColor_ = QColor(0, 0, 0, 175);

    int displayTime_ = 2500;
};
}  // namespace tk
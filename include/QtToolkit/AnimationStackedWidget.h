#ifndef TK_ANIMATION_STACKED_WIDGET_H_
#define TK_ANIMATION_STACKED_WIDGET_H_
#pragma once

#include <QStackedWidget>
#include <QPropertyAnimation>
#include "QtToolkit/TKGlobal.h"

namespace tk {
class TK_API AnimationStackedWidget : public QStackedWidget {
    Q_OBJECT
    Q_PROPERTY(float currentValue READ value WRITE setValue)
   public:
    enum class Module {
        TopToBottom,
        BottomToTop,
        LeftToRight,
        RightToLeft,
        RollInOut,
        FadeInOut,
        BlackInOut,
        SlideInOut,
        CoverInOutLeft,
        CoverInOutRight,
        FadeExchange,
        VerticalFlipRotate,
        VerticalFlipRotateOut,
        VerticalCubeRotateT2B,
        VerticalCubeRotateB2T,
        HorizontalFlipRotate
    };

    explicit AnimationStackedWidget(QWidget* parent = nullptr);
    ~AnimationStackedWidget();

    void start(int index);
    void setLength(int length, Module type);

    void setCurve(QEasingCurve::Type curve);
    void setRevert(bool revert);

    void setDuration(int duration);
    int duration() const;

    void setFadeEnable(bool enable);
    void setAnimatEnable(bool animat);

    void addWidget(QWidget* widget);

    bool isAnimating();

    float value() const;
    void setValue(const float value);

    virtual QSize sizeHint() const override final;

   Q_SIGNALS:
    void pageChanged(int index);

   public Q_SLOTS:
    void setCurrentIndex(int index);

   protected Q_SLOTS:
    void animationFinished();

   protected:
    virtual void paintEvent(QPaintEvent* event) override final;

    void renderPreviousWidget(QPainter* painter, QTransform& transform);
    void renderCurrentWidget(QPainter* painter, QTransform& transform);

    bool isAnimating_;
    float currentValue_;
    float rangeValue_;
    float startValue_;
    float endValue_;

    bool fade_;
    bool animat_;

    QEasingCurve::Type curve_;
    int currentIndex_, previousIndex_;
    Module type_;
    QPropertyAnimation* animation_;

    bool revert_;

    QPixmap privPixmap_;
    QPixmap currentPixmap_;
};
}  // namespace tk
#endif  // !TK_ANIMATION_STACKED_WIDGET_H_

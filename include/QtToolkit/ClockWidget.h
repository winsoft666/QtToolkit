#pragma once

#include "QtToolkit/TKGlobal.h"
#include <QWidget>

namespace tk {
/*
* 时钟表盘
*/
class TK_API ClockWidget : public QWidget {
    Q_OBJECT
    Q_ENUMS(SecondStyle)
    Q_PROPERTY(SecondStyle secondStyle_ READ getSecondStyle WRITE setSecondStyle)

   public:
    enum SecondStyle {
        SS_Unknown = 0,   // 未知
        SS_Normal = 0,    //普通效果(默认)
        SS_Spring = 1,    //弹簧效果
        SS_Continue = 2,  //连续效果
        SS_Hide = 3       //隐藏效果
    };

    explicit ClockWidget(QWidget* parent = nullptr);
    ~ClockWidget();

   public:
    SecondStyle getSecondStyle() const;
    QSize minimumSizeHint() const;

   public Q_SLOTS:
    //设置时钟背景
    void setClockBackground(const QImage& img);
    // 设置时针图片
    void setHourImage(const QImage& img);
    // 设置分针图片
    void setMinuteImage(const QImage& img);
    // 设置秒针图片
    void setSecondImage(const QImage& img);
    // 设置中间点图片
    void setDotImage(const QImage& img);
    //设置秒针走动样式
    void setSecondStyle(const SecondStyle& secondStyle);

   protected:
    void paintEvent(QPaintEvent*) override;

    void drawBg(QPainter* painter);
    void drawHour(QPainter* painter);
    void drawMin(QPainter* painter);
    void drawSec(QPainter* painter);
    void drawDot(QPainter* painter);

   protected Q_SLOTS:
    void updateTime();
    void updateSpring();

   protected:
    SecondStyle secondStyle_;  //秒针走动样式

    QImage clockBg_;    //时钟背景
    QImage clockHour_;  //时针图片
    QImage clockMin_;   //分针图片
    QImage clockSec_;   //秒针图片
    QImage clockDot_;   //中间点图片

    QTimer* timer_;                //定时器计算时间
    int hour_, min_, sec_, msec_;  //时分秒毫秒

    QTimer* timerSpring_;  //定时器显示弹簧效果
    double angleSpring_;   //弹簧角度
};
}  // namespace tk

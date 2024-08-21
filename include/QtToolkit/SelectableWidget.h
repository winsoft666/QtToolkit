#pragma once

#include "QtToolkit/TKGlobal.h"
#include <QWidget>

namespace tk {
class TK_API SelectableWidget : public QWidget {
    Q_OBJECT
    Q_ENUMS(PointStyle)

    Q_PROPERTY(bool drawPoint_ READ getDrawPoint WRITE setDrawPoint)
    Q_PROPERTY(int padding_ READ getPadding WRITE setPadding)
    Q_PROPERTY(int borderWidth_ READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(int pointSize_ READ getPointSize WRITE setPointSize)
    Q_PROPERTY(QColor pointColor_ READ getPointColor WRITE setPointColor)
    Q_PROPERTY(PointStyle pointStyle_ READ getPointStyle WRITE setPointStyle)

   public:
    enum PointStyle {
        PS_Rect = 0,   //正方形
        PS_Circle = 1  //圆形
    };

    explicit SelectableWidget(QWidget* parent = 0);

   public:
    bool getDrawPoint() const;
    int getPadding() const;
    int getBorderWidth() const;
    int getPointSize() const;
    QColor getPointColor() const;
    PointStyle getPointStyle() const;

    QWidget* getWidget() const;
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

   public Q_SLOTS:
    //设置是否绘制描点
    void setDrawPoint(bool drawPoint);
    //设置跟随窗体的边距
    void setPadding(int padding);
    //设置线条宽度
    void setBorderWidth(int borderWidth);
    //设置描点的尺寸
    void setPointSize(int pointSize);
    //设置描点的颜色
    void setPointColor(const QColor& pointColor);
    //设置描点的样式
    void setPointStyle(const PointStyle& pointStyle);

    //设置跟随窗体
    void setWidget(QWidget* widget);

   Q_SIGNALS:
    void widgetPressed(QWidget* widget);
    void widgetRelease(QWidget* widget);
    void widgetDelete(QWidget* widget);

   protected:
    bool eventFilter(QObject* watched, QEvent* event);
    void resizeEvent(QResizeEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*);
    void drawRect(QPainter* painter);
    void drawCircle(QPainter* painter);
    void drawBorder(QPainter* painter);

   protected:
    bool drawPoint_;         //绘制描点
    int padding_;            //窗体的边距
    int borderWidth_;        //边框宽度
    int pointSize_;          //描点的尺寸
    QColor pointColor_;      //描点的颜色
    PointStyle pointStyle_;  //描点的形状

    bool pressed_;             //鼠标按下
    bool pressedLeft_;         //鼠标按下左侧
    bool pressedRight_;        //鼠标按下右侧
    bool pressedTop_;          //鼠标按下上侧
    bool pressedBottom_;       //鼠标按下下侧
    bool pressedLeftTop_;      //鼠标按下左上侧
    bool pressedRightTop_;     //鼠标按下右上侧
    bool pressedLeftBottom_;   //鼠标按下左下侧
    bool pressedRightBottom_;  //鼠标按下右下侧

    int rectX_, rectY_, rectW_, rectH_;  //窗体坐标+宽高
    QPoint lastPos_;                     //鼠标按下处坐标

    QRectF rectLeft_;         //左侧区域
    QRectF rectRight_;        //右侧区域
    QRectF rectTop_;          //上侧区域
    QRectF rectBottom_;       //下侧区域
    QRectF rectLeftTop_;      //左上侧区域
    QRectF rectRightTop_;     //右上侧区域
    QRectF rectLeftBottom_;   //左下侧区域
    QRectF rectRightBottom_;  //右下侧区域
    QWidget* widget_;         //跟随的窗体
};
}  // namespace tk

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
        PS_Rect = 0,   //������
        PS_Circle = 1  //Բ��
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
    //�����Ƿ�������
    void setDrawPoint(bool drawPoint);
    //���ø��洰��ı߾�
    void setPadding(int padding);
    //�����������
    void setBorderWidth(int borderWidth);
    //�������ĳߴ�
    void setPointSize(int pointSize);
    //����������ɫ
    void setPointColor(const QColor& pointColor);
    //����������ʽ
    void setPointStyle(const PointStyle& pointStyle);

    //���ø��洰��
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
    bool drawPoint_;         //�������
    int padding_;            //����ı߾�
    int borderWidth_;        //�߿���
    int pointSize_;          //���ĳߴ�
    QColor pointColor_;      //������ɫ
    PointStyle pointStyle_;  //������״

    bool pressed_;             //��갴��
    bool pressedLeft_;         //��갴�����
    bool pressedRight_;        //��갴���Ҳ�
    bool pressedTop_;          //��갴���ϲ�
    bool pressedBottom_;       //��갴���²�
    bool pressedLeftTop_;      //��갴�����ϲ�
    bool pressedRightTop_;     //��갴�����ϲ�
    bool pressedLeftBottom_;   //��갴�����²�
    bool pressedRightBottom_;  //��갴�����²�

    int rectX_, rectY_, rectW_, rectH_;  //��������+���
    QPoint lastPos_;                     //��갴�´�����

    QRectF rectLeft_;         //�������
    QRectF rectRight_;        //�Ҳ�����
    QRectF rectTop_;          //�ϲ�����
    QRectF rectBottom_;       //�²�����
    QRectF rectLeftTop_;      //���ϲ�����
    QRectF rectRightTop_;     //���ϲ�����
    QRectF rectLeftBottom_;   //���²�����
    QRectF rectRightBottom_;  //���²�����
    QWidget* widget_;         //����Ĵ���
};
}  // namespace tk

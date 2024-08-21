#pragma once

#include "QtToolkit/TKGlobal.h"
#include <QWidget>

namespace tk {
/*
* ʱ�ӱ���
*/
class TK_API ClockWidget : public QWidget {
    Q_OBJECT
    Q_ENUMS(SecondStyle)
    Q_PROPERTY(SecondStyle secondStyle_ READ getSecondStyle WRITE setSecondStyle)

   public:
    enum SecondStyle {
        SS_Unknown = 0,   // δ֪
        SS_Normal = 0,    //��ͨЧ��(Ĭ��)
        SS_Spring = 1,    //����Ч��
        SS_Continue = 2,  //����Ч��
        SS_Hide = 3       //����Ч��
    };

    explicit ClockWidget(QWidget* parent = nullptr);
    ~ClockWidget();

   public:
    SecondStyle getSecondStyle() const;
    QSize minimumSizeHint() const;

   public Q_SLOTS:
    //����ʱ�ӱ���
    void setClockBackground(const QImage& img);
    // ����ʱ��ͼƬ
    void setHourImage(const QImage& img);
    // ���÷���ͼƬ
    void setMinuteImage(const QImage& img);
    // ��������ͼƬ
    void setSecondImage(const QImage& img);
    // �����м��ͼƬ
    void setDotImage(const QImage& img);
    //���������߶���ʽ
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
    SecondStyle secondStyle_;  //�����߶���ʽ

    QImage clockBg_;    //ʱ�ӱ���
    QImage clockHour_;  //ʱ��ͼƬ
    QImage clockMin_;   //����ͼƬ
    QImage clockSec_;   //����ͼƬ
    QImage clockDot_;   //�м��ͼƬ

    QTimer* timer_;                //��ʱ������ʱ��
    int hour_, min_, sec_, msec_;  //ʱ�������

    QTimer* timerSpring_;  //��ʱ����ʾ����Ч��
    double angleSpring_;   //���ɽǶ�
};
}  // namespace tk

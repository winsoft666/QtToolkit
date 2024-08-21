#pragma once
#include "QtToolkit/TKGlobal.h"
#include <QLabel>
#include <QBasicTimer>

namespace tk {
/*
* ���������ʾ���ı�
*/
class TK_API RollLabel : public QLabel {
    Q_OBJECT
   public:
    explicit RollLabel(QWidget* parent = nullptr);

    // ��ȡ�������ƶ���ʱ��ʱ���������룩
    int getInterval() const;
    void setInterval(int interval);

    // ��ȡ������ÿ�ֿ�ʼǰ��ͣʱ�䣨���룩
    void setInitialFreezingMS(int ms);
    int initialFreezingMS() const;

    // ��ȡ������ÿ�ֿ�ʼǰ���ı��ĳ�ʼλ�ã�X��λ�ƣ�
    void setInitialOffsetPercent(float percent);
    float initialOffsetPercent() const;

   protected:
    void timerEvent(QTimerEvent* e) override;
    void paintEvent(QPaintEvent* e) override;
    void resizeEvent(QResizeEvent* e) override;

    void showEvent(QShowEvent* e) override;
    void hideEvent(QHideEvent* e) override;

   protected:
    int interval_ = 30;
    int initialFreezingMS_ = 200;
    float initOffsetPercent_ = 0.4f;
    int curOffset_ = 0;
    qint64 freezingStartTime_ = 0LL;
    bool nextTimeWillFreezing_ = false;
    QBasicTimer scrollTimer_;
};
}  // namespace tk
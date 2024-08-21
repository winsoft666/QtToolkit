#pragma once
#include "QtToolkit/TKGlobal.h"
#include <QLabel>
#include <QBasicTimer>

namespace tk {
/*
* 横向滚动显示的文本
*/
class TK_API RollLabel : public QLabel {
    Q_OBJECT
   public:
    explicit RollLabel(QWidget* parent = nullptr);

    // 获取和设置移动定时器时间间隔（毫秒）
    int getInterval() const;
    void setInterval(int interval);

    // 获取和设置每轮开始前暂停时间（毫秒）
    void setInitialFreezingMS(int ms);
    int initialFreezingMS() const;

    // 获取和设置每轮开始前，文本的初始位置（X轴位移）
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
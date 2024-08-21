#pragma once
#include "QtToolkit/TKGlobal.h"
#include <QLabel>
#include <QResizeEvent>

namespace tk {
/*
* �Զ��ı��ı���С�����ı�������������ؼ�����
*/
class TK_API StuffLabel : public QLabel {
    Q_OBJECT
   public:
    explicit StuffLabel(QWidget* parent = nullptr);
    StuffLabel(QString text, QWidget* parent = nullptr);

    int maximumFontPixelSize() const;
    int minimumFontPixelSize() const;

   public Q_SLOTS:
    void setMaximumFontPixelSize(int size);
    void setMinimumFontPixelSize(int size);

   protected:
    void layout();
    QRect documentRect();

   protected:
    virtual void resizeEvent(QResizeEvent* e) override;

    int maximumFontPixelSize_ = 0;
    int minimumFontPixelSize_ = 0;
};
}  // namespace tk

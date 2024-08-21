#ifndef FLOWLAYOUT_H
#define FLOWLAYOUT_H

#include "QtToolkit/TKGlobal.h"
#include <QLayout>
#include <QRect>
#include <QStyle>

namespace tk {
/*
* 流式布局容器
*/
class TK_API FlowLayout : public QLayout {
   public:
    explicit FlowLayout(QWidget* parent,
                          int margin = -1,
                          int hSpacing = -1,
                          int vSpacing = -1);
    explicit FlowLayout(int margin = -1,
                          int hSpacing = -1,
                          int vSpacing = -1);
    virtual ~FlowLayout();

    void addItem(QLayoutItem* item) override;

    int horizontalSpacing() const;
    int verticalSpacing() const;

    Qt::Orientations expandingDirections() const override;

    bool hasHeightForWidth() const override;
    int heightForWidth(int) const override;

    int count() const override;

    QLayoutItem* itemAt(int index) const override;

    QSize minimumSize() const override;
    void setGeometry(const QRect& rect) override;
    QSize sizeHint() const override;
    QLayoutItem* takeAt(int index) override;

   private:
    int doLayout(const QRect& rect, bool testOnly) const;
    int smartSpacing(QStyle::PixelMetric pm) const;

    QList<QLayoutItem*> itemList_;
    int hSpace_ = 0;
    int vSpace_ = 0;
};
}  // namespace tk
#endif

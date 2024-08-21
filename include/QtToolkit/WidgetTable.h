#ifndef TK_WIDGET_TABLE_H_
#define TK_WIDGET_TABLE_H_
#pragma once

#include "QtToolkit/TKGlobal.h"
#include <QGridLayout>
#include <QResizeEvent>
#include <QAbstractScrollArea>

namespace tk {
class TK_API WidgetTable : public QAbstractScrollArea {
    Q_OBJECT
   public:
    WidgetTable(QWidget* parent = Q_NULLPTR);

   signals:
    void cellCountHintChanged(int rowCount, int columnCount);

   public Q_SLOTS:
    void setColumnCount(int colCount);
    void setSpacing(int horizontalSpacing, int verticalSpacing);

    void beginBatchAppend();
    void appendWidget(QWidget* w);
    void removeAll();
    void endBatchAppend();
    void setCellCountHintChangedNoitfyEnabled(bool enabled, QSize widgetFixedSize);

   public:
    int horizontalSpacing() const;
    int verticalSpacing() const;

    QWidget* widgetAt(int row, int col) const;
    int itemCount() const;

    int columnCount() const;
    int rowCount() const;

    bool columnCountHintChangedNotifyEnabled() const;
    QSize widgetFixedSize() const;

    QGridLayout* gridLayout();

   protected Q_SLOTS:
    void horizontalScrollBarValueChanged(int value);
    void verticalScrollBarValueChanged(int value);

    void updateGridWidgetSize();
    void updateScrollBars();

   protected:
    bool viewportEvent(QEvent* e) override;
    
    // 在不显示滚动条的情况下，能显示的最大行数和列数
    int getMaxRowNum(int height);
    int getMaxColumnNum(int width);
   protected:
    bool inBatchAppend_ = false;
    bool cellCountHintEnabled_ = false;
    QSize widgetFixedSize_ = QSize(100, 100);

    int colCount_ = 0;
    int itemCount_ = 0;

    QGridLayout* grid_ = Q_NULLPTR;
    QWidget* w_ = Q_NULLPTR;
};
}  // namespace tk

#endif  // !TK_WIDGET_TABLE_H_

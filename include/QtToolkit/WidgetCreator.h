#ifndef TK_WIDGET_CREATOR_H_
#define TK_WIDGET_CREATOR_H_
#pragma once
#include "QtToolkit/TKGlobal.h"
#include <QRect>
#include <QString>
#include <QLabel>
#include <QPainterPath>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace tk {
/*
* 快捷创建布局和Widget
*/
TK_API QHBoxLayout* CreateHLayout(int childSpace = 0);
TK_API QVBoxLayout* CreateVLayout(int childSpace = 0);

TK_API QLabel* CreateLabel(const QString& objectName,
                                     const QString& text,
                                     Qt::Alignment alignment = Qt::AlignLeft | Qt::AlignVCenter,
                                     int width = 0,   // 0 = Preferred   -1 = Expanding   >0 = Fixed
                                     int height = 0,  // 0 = Preferred   -1 = Expanding   >0 = Fixed
                                     QWidget* parent = Q_NULLPTR);

TK_API QPushButton* CreateButton(const QString& objectName,
                                           const QString& text,
                                           int width = 0,   // 0 = Preferred   -1 = Expanding   >0 = Fixed
                                           int height = 0,  // 0 = Preferred   -1 = Expanding   >0 = Fixed
                                           QWidget* parent = Q_NULLPTR);

}  // namespace tk
#endif // !TK_WIDGET_CREATOR_H_
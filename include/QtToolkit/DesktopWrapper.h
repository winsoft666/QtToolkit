#pragma once

#include <QWidget>
#include "QtToolkit/TKGlobal.h"

namespace tk {
class DesktopWrapper {
   public:
    // 根据屏幕索引获取屏幕Geometry
    static QRect screenGeometry(int index = 0);
    
    // 对于多屏幕，返回所有屏幕拼接后的Geometry
    static QRect totalGeometry();

    // 对QWidget的指定区域截图

    static QPixmap grabWidget(QWidget* widget, const QRect& rect);
    
    // 对屏幕的指定区域截图
    static QPixmap grabWindow(int x = 0, int y = 0, int w = -1, int h = -1);
};
}  // namespace tk
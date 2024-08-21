#pragma once

#include <QWidget>
#include "QtToolkit/TKGlobal.h"

namespace tk {
class DesktopWrapper {
   public:
    // ������Ļ������ȡ��ĻGeometry
    static QRect screenGeometry(int index = 0);
    
    // ���ڶ���Ļ������������Ļƴ�Ӻ��Geometry
    static QRect totalGeometry();

    // ��QWidget��ָ�������ͼ

    static QPixmap grabWidget(QWidget* widget, const QRect& rect);
    
    // ����Ļ��ָ�������ͼ
    static QPixmap grabWindow(int x = 0, int y = 0, int w = -1, int h = -1);
};
}  // namespace tk
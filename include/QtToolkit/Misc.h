#pragma once

#include "QtToolkit/TKGlobal.h"
#include <QRect>
#include <QPainterPath>
#include <QWidget>
#include <QPixmap>
#include <QLayout>
#include "RectVertex.h"

#ifdef Q_OS_WIN
#ifndef _INC_WINDOWS
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif  // !WIN32_LEAN_AND_MEAN
#endif  // !_INC_WINDOWS

#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_
#endif  // !_WINSOCKAPI_

#include <Windows.h>
#endif

namespace tk {
// 将w居中显示在host中
// 如果host为Q_NULLPTR，则居中显示在w的父控件中；
// 如果host为Q_NULLPTR且w没有父控件，则居中显示在当前w所在屏幕的中间；
TK_API void CenterWidgetsInHost(QWidget* w, QWidget* host = Q_NULLPTR);

// 创建一个带有圆角的矩形路径
// vertex 参数用于指定矩形四个角的radius
TK_API QPainterPath CreateRadiusRectPath(QRect rect, RectVertex vertex);

// 震动
TK_API void ShockWidget(QWidget* widget);

// 根据指定的字体、最大宽度（像素）截断strText文本
// 如果文本可以完全显示，则返回文本；
// 如果文本不能完全显示，则最大截断文本，并在末尾添加"..."
TK_API QString GetElideText(const QFont& font, int maxPixels, const QString& strText);

#ifdef Q_OS_WIN
// 鼠标穿透
TK_API void SetMousePenetrate(HWND h, bool penetrate);

TK_API QImage QImageFromHBITMAP(HDC hdc, HBITMAP bitmap, int w, int h);
TK_API QImage QImageFromHICON(HICON icon);
#endif

// 获取指定颜色的反向颜色
TK_API QColor GetInvertColor(const QColor& color);

// 获取图片主题色
TK_API QColor GetImageThemeColor(const QImage& img, double bright);

// 采用九宫格模式进行图片缩放
// keepVertexImageSize 保持顶点图片大小不变，此时如果顶点图片宽或高已经大于了目标宽高，则直接返回原图
TK_API QPixmap ScaleByNinePatch(const QPixmap& src,
                                QSize destSize,
                                bool keepVertexImageSize,
                                int pos1Width,
                                int pos1Height,
                                int pos3Width,
                                int pos7Height,
                                Qt::TransformationMode mode = Qt::SmoothTransformation);

// 返回最大的字体大小
// 该字体大小是按照指定的font字体（不含pixel size），使得text文本能填充满指定区域rc的text的最大字体大小
TK_API int GetMaxFontPixelSize(const QRect& rc, const QString& text, const QFont& font, bool isWordWarp);

TK_API void ClearLayout(QLayout* layout);

TK_API QRectF GetCenterMaxSquare(const QRect& rc);

TK_API QString PointToStr(const QPoint& pt);
TK_API bool StrToPoint(const QString& str, QPoint& pt);
TK_API QPoint StrToPoint(const QString& str, const QPoint& def);

TK_API QString SizeToStr(const QSize& s);
TK_API bool StrToSize(const QString& str, QSize& s);
TK_API QSize StrToSize(const QString& str, const QSize& def);

TK_API QString RectToStr(const QRect& rc);
TK_API bool StrToRect(const QString& str, QRect& rc);
TK_API QRect StrToRect(const QString& str, const QRect& def);

TK_API QString MarginsToStr(const QMargins& m);
TK_API bool StrToMargins(const QString& str, QMargins& m);
TK_API QMargins StrToMargins(const QString& str, const QMargins& def);

TK_API QString ColorToStr(const QColor& clr);
TK_API bool StrToColor(const QString& str, QColor& clr);
TK_API QColor StrToColor(const QString& str, const QColor& def);
}  // namespace tk
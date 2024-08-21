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
// ��w������ʾ��host��
// ���hostΪQ_NULLPTR���������ʾ��w�ĸ��ؼ��У�
// ���hostΪQ_NULLPTR��wû�и��ؼ����������ʾ�ڵ�ǰw������Ļ���м䣻
TK_API void CenterWidgetsInHost(QWidget* w, QWidget* host = Q_NULLPTR);

// ����һ������Բ�ǵľ���·��
// vertex ��������ָ�������ĸ��ǵ�radius
TK_API QPainterPath CreateRadiusRectPath(QRect rect, RectVertex vertex);

// ��
TK_API void ShockWidget(QWidget* widget);

// ����ָ�������塢����ȣ����أ��ض�strText�ı�
// ����ı�������ȫ��ʾ���򷵻��ı���
// ����ı�������ȫ��ʾ�������ض��ı�������ĩβ���"..."
TK_API QString GetElideText(const QFont& font, int maxPixels, const QString& strText);

#ifdef Q_OS_WIN
// ��괩͸
TK_API void SetMousePenetrate(HWND h, bool penetrate);

TK_API QImage QImageFromHBITMAP(HDC hdc, HBITMAP bitmap, int w, int h);
TK_API QImage QImageFromHICON(HICON icon);
#endif

// ��ȡָ����ɫ�ķ�����ɫ
TK_API QColor GetInvertColor(const QColor& color);

// ��ȡͼƬ����ɫ
TK_API QColor GetImageThemeColor(const QImage& img, double bright);

// ���þŹ���ģʽ����ͼƬ����
// keepVertexImageSize ���ֶ���ͼƬ��С���䣬��ʱ�������ͼƬ�����Ѿ�������Ŀ���ߣ���ֱ�ӷ���ԭͼ
TK_API QPixmap ScaleByNinePatch(const QPixmap& src,
                                QSize destSize,
                                bool keepVertexImageSize,
                                int pos1Width,
                                int pos1Height,
                                int pos3Width,
                                int pos7Height,
                                Qt::TransformationMode mode = Qt::SmoothTransformation);

// �������������С
// �������С�ǰ���ָ����font���壨����pixel size����ʹ��text�ı��������ָ������rc��text����������С
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
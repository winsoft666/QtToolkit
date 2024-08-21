#pragma once

#define TK_QT_VERSION_GTE(major, minor, patch) (QT_VERSION >= QT_VERSION_CHECK(major, minor, patch))

/// Font string width
#if TK_QT_VERSION_GTE(5, 11, 0)
#define TKFontWidth(p, t) p.horizontalAdvance(t)
#else
#define TKFontWidth(p, t) p.width(t)
#endif
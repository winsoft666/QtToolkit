#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_TK_STATIC
#if defined(TK_LIB)
#define TK_API Q_DECL_EXPORT
#else
#define TK_API Q_DECL_IMPORT
#endif
#else
#define TK_API
#endif

#pragma execution_character_set("utf-8")

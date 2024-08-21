#ifndef TK_SMOOTHCURVECREATOR_H
#define TK_SMOOTHCURVECREATOR_H
#pragma once

#include "QtToolkit/TKGlobal.h"
#include <QList>
#include <QPointF>
#include <QPainterPath>

namespace tk {
class TK_API SmoothCurveCreator {
   public:
    static QPainterPath CreateSmoothCurve(const QVector<QPointF>& points);

   private:
    static void calculateFirstControlPoints(double*& result, const double* rhs, int n);
    static void calculateBezierCurveControlPoints(const QVector<QPointF>& knots,
                                                  QVector<QPointF>* firstControlPoints,
                                                  QVector<QPointF>* secondControlPoints);
};
}  // namespace tk
#endif  // TK_SMOOTHCURVECREATOR_H

#include "cgtriangleneedle.h"
#include "cgwidget.h"

CGTriangleNeedle::CGTriangleNeedle(CGWidget *parent) : CGNeedle(parent)
{
}

void CGTriangleNeedle::draw(QPainter *painter)
{
    painter->save();
    painter->translate(_parent->center());
    float deg = getDegFromValue(_currentValue);
    painter->rotate(270-deg);
    painter->setBrush(QBrush(_color));
    painter->setPen(Qt::NoPen);

    float r = _parent->radius();
    float origin = relToAbs(r,_rPos);
    float length = relToAbs(r,_rLength);
    float width = relToAbs(r,_rWidth);
    QVector<QPointF> points;
    points.append(QPointF(0.0, origin+length));
    points.append(QPointF(-width, origin));
    points.append(QPointF(width,origin));

    painter->drawConvexPolygon(points);
    painter->restore();
}

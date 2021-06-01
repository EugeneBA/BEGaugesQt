#include "cgtrapezeneedle.h"
#include "cgwidget.h"

CGTrapezeNeedle::CGTrapezeNeedle(CGWidget *parent) : CGNeedle(parent)
{
    _aspect = 0.5;
}

void CGTrapezeNeedle::draw(QPainter *painter)
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
    float smallwidth = width*_aspect;

    QVector<QPointF> points;
    points.append(QPointF(-width,origin));
    points.append(QPointF(-smallwidth, origin+length));
    points.append(QPointF(smallwidth, origin+length));
    points.append(QPointF(width,origin));

    painter->drawConvexPolygon(points);
    painter->restore();
}

void CGTrapezeNeedle::setAspect(float aspect)
{
    aspect = qBound(0.0f,aspect,1.0f);
    if(_aspect == aspect)
        return;
    _aspect = aspect;
    update();
}

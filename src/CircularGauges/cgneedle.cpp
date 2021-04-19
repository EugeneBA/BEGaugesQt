#include "cgneedle.h"
#include "cgwidget.h"

CGNeedle::CGNeedle(CGWidget *parent) : CGScale(parent)
{
    _currentValue = 0;
    _rPos = 0;
    _rLength = 0.9f;
    _rWidth = 5;
}

void CGNeedle::setCurrentValue(float value)
{
    value = qBound(_minValue,value,_maxValue);

    if(_currentValue == value)
        return;

    _currentValue = value;
    update();
}

void CGNeedle::setrLength(float rLength)
{
    if(_rLength == rLength)
        return;
    _rLength = rLength;
    update();
}

void CGNeedle::setrWidth(float rWidth)
{
    if(_rWidth == rWidth)
        return;
    _rWidth = rWidth;
    update();
}

void CGNeedle::createFeatherNeedle(float r)
{
    QVector<QPointF> tmpPoints;
    tmpPoints.append(QPointF(0.0, r));
    tmpPoints.append(QPointF(-r/40.0, 0.0));
    tmpPoints.append(QPointF(-r/15.0, -r/5.0));
    tmpPoints.append(QPointF(r/15.0,-r/5));
    tmpPoints.append(QPointF(r/40.0,0.0));
    //mNeedlePoly = tmpPoints;
}

void CGNeedle::createAttitudeNeedle(float r)
{
    QVector<QPointF> tmpPoints;
    tmpPoints.append(QPointF(0.0, r));
    tmpPoints.append(QPointF(-r/20.0, 0.85*r));
    tmpPoints.append(QPointF(r/20.0,0.85*r));
    //mNeedlePoly = tmpPoints;
}

void CGNeedle::createCompassNeedle(float r)
{
    QVector<QPointF> tmpPoints;
    tmpPoints.append(QPointF(0.0, r));
    tmpPoints.append(QPointF(-r/15.0, 0.0));
    tmpPoints.append(QPointF(0.0, -r));
    tmpPoints.append(QPointF(r/15.0,0.0));
   // mNeedlePoly = tmpPoints;
}



CGRhombusleNeedle::CGRhombusleNeedle(CGWidget *parent) : CGNeedle(parent)
{
}

void CGRhombusleNeedle::draw(QPainter *painter)
{
    painter->save();
    painter->translate(_parent->center());
    float deg = getDegFromValue(_currentValue);
    painter->rotate(270-deg);
    painter->setBrush(QBrush(_color));
    painter->setPen(Qt::NoPen);

    //QLinearGradient grad;

    //        createCompassNeedle(getRadius(tmpRect));
    //        grad.setStart(mNeedlePoly[0]);
    //        grad.setFinalStop(mNeedlePoly[1]);
    //        grad.setColorAt(0.9,Qt::red);
    //        grad.setColorAt(1,Qt::blue);
    //        painter->setBrush(grad);

    float r = _parent->radius();
    float origin = rPosToPoints(r,_rPos);
    float length = rPosToPoints(r,_rLength);
    float width = rPosToPoints(r,_rWidth);
    QVector<QPointF> points;
    points.append(QPointF(0.0, origin));
    points.append(QPointF(-width,origin+width));
    points.append(QPointF(0.0, origin+length));
    points.append(QPointF(width,origin+width));

    painter->drawConvexPolygon(points);
    painter->restore();
}



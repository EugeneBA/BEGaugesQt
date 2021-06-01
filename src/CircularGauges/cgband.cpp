#include "cgband.h"
#include"cgwidget.h"

CGBand::CGBand(CGWidget *parent) : CGScale(parent)
{
    _beginValue = 10;
    _endValue =90;
    _rWidth = 5;
}

QPainterPath CGBand::createSubBand(float from, float sweep)
{
    QRectF rect = adjustRect(_parent->gaugeFullRect(),_rPos);
    QPainterPath path;
    path.arcMoveTo(rect,from);
    path.arcTo(rect,from,sweep);
    return path;
}

float CGBand::beginValue() const
{
    return _beginValue;
}

void CGBand::setBeginValue(float beginValue)
{
    _beginValue = beginValue;
}

float CGBand::endValue() const
{
    return _endValue;
}

void CGBand::setEndValue(float endValue)
{
    _endValue = endValue;
}

void CGBand::setBand(float beginValue, float endValue)
{
    if(beginValue<_minValue)
        beginValue = _minValue;
    else if(beginValue> _maxValue)
        beginValue = _maxValue;

    if(endValue > _maxValue)
        endValue = _maxValue;

    _beginValue = beginValue;
    _endValue = endValue;
    update();
}

void CGBand::draw(QPainter *painter)
{
    float r = _parent->radius();
    QPen pen;
    pen.setCapStyle(Qt::FlatCap);
    pen.setWidthF(relToAbs(r,_rWidth));
    painter->setBrush(Qt::NoBrush);

    float beg = getDegFromValue(_beginValue);
    float sweep = getDegFromValue(_endValue) - beg;

    QPainterPath path = createSubBand(beg,sweep);
    pen.setColor(_color);
    painter->setPen(pen);
    painter->drawPath(path);

}

void CGBand::setrWidth(float rWidth)
{
    _rWidth = rWidth;
    update();
}

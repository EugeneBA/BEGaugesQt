#include "cgticks.h"
#include"cgwidget.h"


CGTicks::CGTicks(CGWidget *parent) : CGScale(parent)
{
    _step = 10;
    _subTicks = false;

    _rLength = 5;
    _rWidth = 3;
}


void CGTicks::draw(QPainter *painter)
{
    painter->setPen(_color);

    float r = _parent->radius();

    float origin = relToAbs(r,_rPos);
    float length = relToAbs(r,_rLength);
    float width = relToAbs(r,_rWidth);

    for(float val = _minValue;val<=_maxValue;val+=_step)
    {
        float deg = getDegFromValue(val);
        QPointF start = _parent->point(origin, deg);
        QPointF end = _parent->point(origin+length, deg);

        QPen pen;
        pen.setColor(_color);
        if(_subTicks)
            pen.setWidthF(width*0.5);
        else
            pen.setWidthF(width);

        painter->setPen(pen);
        painter->drawLine(start,end);
    }
}

void CGTicks::setStep(float step)
{
    _step = step;
    update();
}

void CGTicks::setSubDegree(bool b)
{
    _subTicks = b;
    update();
}

void CGTicks::setrLength(float rLength)
{
    _rLength = rLength;
    update();
}

void CGTicks::setrWidth(float rWidth)
{
    _rWidth = rWidth;
    update();
}

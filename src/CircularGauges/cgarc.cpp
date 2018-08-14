#include "cgarc.h"
#include"cgwidget.h"

CGArc::CGArc(CGWidget *parent) :   CGScale(parent)
{    
 _rWidth = 3;
}

void CGArc::draw(QPainter *painter)
{
    float r = _parent->radius();

    QRectF arcRect = adjustRect(_parent->gaugeFullRect(),_rPos);

    QPen pen;
    pen.setColor(_color);
    pen.setWidthF(rPosToPoints(r,_rWidth));
    painter->setPen(pen);
    painter->drawArc(arcRect,16*_minDegree,16*(_maxDegree-_minDegree));
}

void CGArc::setrWidth(float rWidth)
{
    _rWidth = rWidth;
    update();
}

#include "cgitem.h"
#include<qmath.h>
#include"cgwidget.h"


CGItem::CGItem(CGWidget *parent) :
    QObject(parent)
{
    _parent = parent;
    _rPos = 0.5f;
    _color = Qt::black;
}

void CGItem::update()
{
    _parent->update();
}

QRectF CGItem::rect()
{
    return mRect;
}

void CGItem::setrPos(float rpos)
{
    _rPos = rpos;
    update();
}

void CGItem::setColor(const QColor &color)
{
    _color = color;
    update();
}

QRectF CGItem::adjustRect(const QRectF& rect, float rpos)
{
    float radius = _parent->radius();
    float offset =   radius - relToAbs(radius,rpos);
    QRectF tmpRect = rect.adjusted(offset,offset,-offset,-offset);
    return tmpRect;
}

float CGItem::relToAbs(float basis, float relValue)
{
    if(relValue<=0)
        return 0.0f;
    if(relValue>=1.45)
        return relValue;

    return basis*relValue;
}

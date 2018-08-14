#include "cgscale.h"
#include "cgwidget.h"

CGScale::CGScale(CGWidget *parent) : CGItem(parent)
{
    _minDegree = _parent->minAngle();
    _maxDegree = _parent->maxAngle();
    _minValue = 0;
    _maxValue = 100;
}

void CGScale::setValueRange(float minValue, float maxValue)
{
    if(!(minValue<maxValue))
        throw( InvalidValueRange);
    _minValue = minValue;
    _maxValue = maxValue;
    update();
}

void CGScale::setDegreeRange(float minDegree, float maxDegree)
{
    _minDegree = minDegree;
    _maxDegree = maxDegree;
    update();
}

float CGScale::getDegFromValue(float v)
{
    float a = (_maxDegree-_minDegree)/(_maxValue-_minValue);
    float b = -a*_minValue+_minDegree;
    return a*v+b;
}

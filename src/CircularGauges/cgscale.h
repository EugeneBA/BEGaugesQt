#pragma once

#include "cgitem.h"

class CGScale : public CGItem
{
    Q_OBJECT
public:
    explicit CGScale(CGWidget *parent);

    void setValueRange(float minValue,float maxValue);
    void setDegreeRange(float minDegree,float maxDegree);
    inline float minValue(){return _minValue;}
    inline float maxValue(){return _maxValue;}

protected:
    float getDegFromValue(float);

    float _minValue;
    float _maxValue;
    float _minDegree;
    float _maxDegree;
};

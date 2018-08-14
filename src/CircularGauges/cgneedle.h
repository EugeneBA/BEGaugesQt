#pragma once

#include "cgscale.h"

class CGNeedle : public CGScale
{
    Q_OBJECT
public:
    explicit CGNeedle(CGWidget *parent);

    inline float currentValue(){return _currentValue;}
    void setCurrentValue(float value);

    inline float rLength() {return _rLength;}
    void setrLength(float rLength);

    inline float rWidth() {return _rWidth;}
    void setrWidth(float rWidth);

protected:

    float _rLength;
    float _rWidth;
    float _currentValue;

    void createFeatherNeedle(float r);
    void createAttitudeNeedle(float r);
    void createCompassNeedle(float r);    
};

class QCRhombusleNeedle : public CGNeedle
{
    Q_OBJECT
public:
    explicit QCRhombusleNeedle(CGWidget *parent);
    virtual void draw(QPainter *);
};

#pragma once

#include "cgscale.h"

class CGTicks : public CGScale
{
    Q_OBJECT
public:
    explicit CGTicks(CGWidget *parent);

    void draw(QPainter *painter);
    void setStep(float step);
    void setSubDegree(bool );

    inline float rLength() {return _rLength;}
    void setrLength(float rLength);

    inline float rWidth() {return _rWidth;}
    void setrWidth(float rWidth);

protected:
    float _rLength;
    float _rWidth;

    float _step;
    bool _subTicks;
};

#pragma once

#include "cgscale.h"
#include <QPainterPath>

class CGBand : public CGScale
{
    Q_OBJECT
public:
    explicit CGBand(CGWidget *parent);
    void draw(QPainter*);

    float beginValue() const;
    void setBeginValue(float beginValue);

    float endValue() const;
    void setEndValue(float endValue);

    void setBand(float beginValue,float endValue);

    inline float rWidth() {return _rWidth;}
    void setrWidth(float rWidth);

private:
    QPainterPath createSubBand(float from,float sweep);

    float _beginValue;
    float _endValue;
    float _rWidth;
};

#pragma once

#include"cgscale.h"

class CGValues : public CGScale
{
    Q_OBJECT
public:
    explicit CGValues(CGWidget *parent);

    void draw(QPainter*);
    void setStep(float step);

    inline float rFontSize() {return _rFontSize;}
    void setrFontSize(float rFontSize);

    inline bool boldFont() {return _boldFont;}
    void setBoldFont(bool boldFont);

    inline bool correctPos(){return _correctPos;}
    void setCorrectPos(bool correctPos);

private:
    float _step;

    float _rFontSize;
    bool _boldFont;
    bool _correctPos;
};

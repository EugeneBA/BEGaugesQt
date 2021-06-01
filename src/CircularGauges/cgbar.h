#pragma once

#include "cgscale.h"
#include <QPainterPath>

enum CGBarColorType{
    OneColor,
    MultiColor
};

class CGBar : public CGScale
{
    Q_OBJECT
public:
    explicit CGBar(CGWidget *parent);
    void draw(QPainter*);

    inline float currentValue(){return _currentValue;}
    void setCurrentValue(float value);

    inline float rWidth() {return _rWidth;}
    void setrWidth(float rWidth);

    inline QColor getDefColor(){return _defColor;}
    void setDefColor(const QColor &defColor);

    inline QColor backColor(){return _backColor;}
    void setBackColor(const QColor &backColor);

    QColor getColorFromValue(float value);

    void AddBand(float value,QColor color);
    void SetBands(QList<QPair<float,QColor> > bands);
    QList<QPair<float,QColor>> GetBands();
    void ClearBands();
    void SetFullRangeBand(QColor color);

    inline float ticksWidth() {return _ticksWidth;}
    void setTicksWidth(float ticksWidth);

    inline float ticksStep(){return _ticksStep;}
    void setTicksStep(float ticksStep);

    inline CGBarColorType colorType(){return _colorType;}
    void setColorType(CGBarColorType colorType);

    inline bool drawTicks() {return _drawTicks;}
    void setDrawTicks(bool value);

private:

    float _ticksWidth;
    float _ticksStep;

    float _currentValue;

    QColor _defColor;
    QColor _backColor;
    QList<QPair<float,QColor> > _bands;
    CGBarColorType _colorType;

    QPainterPath createSubBand(float from,float sweep);
    void drawTicks(QPainter *painter);
    void drawLine(QPainter *painter, float angle, float beg, float end);

    float _beginValue;
    float _endValue;
    float _rWidth;

    bool _drawTicks;
};

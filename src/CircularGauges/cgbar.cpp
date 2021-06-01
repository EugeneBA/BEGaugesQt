#include "cgbar.h"
#include"cgwidget.h"

CGBar::CGBar(CGWidget *parent) : CGScale(parent)
{
    _beginValue = 10;
    _endValue =90;
    _rWidth = 5;
    _ticksWidth = 1.5;
    _ticksStep = 1;
    _backColor = Qt::white;
    _colorType = CGBarColorType::MultiColor;
    _drawTicks = true;
}

void CGBar::setCurrentValue(float value)
{
    value = qBound(_minValue,value,_maxValue);

    if(_currentValue == value)
        return;

    _currentValue = value;
    update();
}

QPainterPath CGBar::createSubBand(float from, float sweep)
{
    QRectF rect = adjustRect(_parent->gaugeFullRect(),_rPos);
    QPainterPath path;
    path.arcMoveTo(rect,from);
    path.arcTo(rect,from,sweep);
    return path;
}

void CGBar::draw(QPainter *painter)
{
    float r = _parent->radius();
    QPen pen;
    pen.setCapStyle(Qt::FlatCap);
    pen.setWidthF(relToAbs(r,_rWidth));
    painter->setBrush(Qt::NoBrush);

    float beg = getDegFromValue(_minValue);
    float value = getDegFromValue(_currentValue);
    float end = getDegFromValue(_maxValue);

    QPainterPath path = createSubBand(value,end-value);
    pen.setColor(_backColor);
    painter->setPen(pen);
    painter->drawPath(path);

    QColor curColor = _defColor;

    if(_colorType == CGBarColorType::MultiColor)
    {
        for(int i=0;i<_bands.size();i++)
        {
            if(_currentValue < _bands[i].first)
                break;

            float curband = getDegFromValue(_bands[i].first);
            path = createSubBand(beg,curband - beg);
            pen.setColor(curColor);
            painter->setPen(pen);
            painter->drawPath(path);
            beg = curband;
            curColor = _bands[i].second;
        }
    }
    else
    {
        curColor = getColorFromValue(_currentValue);
    }

    path = createSubBand(beg, value - beg);
    pen.setColor(curColor);
    painter->setPen(pen);
    painter->drawPath(path);

    if(_drawTicks)
        drawTicks(painter);
}

void CGBar::setrWidth(float rWidth)
{
    _rWidth = rWidth;
    update();
}

void CGBar::setDefColor(const QColor &defColor)
{
    _defColor = defColor;
}

void CGBar::setBackColor(const QColor &backColor)
{
    _backColor = backColor;
}

void CGBar::setColorType(CGBarColorType colorType)
{
    _colorType = colorType;
}

QColor CGBar::getColorFromValue(float value)
{
    QColor res = _defColor;

    for(int i=0;i<_bands.size();i++)
    {
        if(value > _bands[i].first)
            res = _bands[i].second;
    }
    return res;
}

void CGBar::AddBand(float value, QColor color)
{
    _bands.append(QPair<float,QColor>(value,color));
    update();
}

void CGBar::SetBands(QList<QPair<float, QColor> > bands)
{
    _bands = bands;
    update();
}

QList<QPair<float, QColor> > CGBar::GetBands()
{
    return _bands;
}

void CGBar::ClearBands()
{
    if(_bands.isEmpty())
        return;
    _bands.clear();
    update();
}

void CGBar::SetFullRangeBand(QColor color)
{
    _bands.clear();
    _bands.append(QPair<float,QColor>(_maxValue,color));
    update();
}

void CGBar::setTicksWidth(float ticksWidth)
{
    if(_ticksWidth == ticksWidth)
        return;
    _ticksWidth = ticksWidth;
    update();
}

void CGBar::setTicksStep(float ticksStep)
{
    if(_ticksStep == ticksStep)
        return;
    _ticksStep = ticksStep;
    update();
}

void CGBar::setDrawTicks(bool value)
{
    if(_drawTicks == value)
        return;
    _drawTicks = value;
    update();
}

void CGBar::drawTicks(QPainter *painter)
{
    QPen pen(_color);
    pen.setWidthF(_ticksWidth);
    painter->setPen(pen);

    float r = _parent->radius();
    auto beg = relToAbs(r, _rPos -_rWidth*0.5);
    auto end = relToAbs(r, _rPos +_rWidth*0.5);

    for(float val = _minValue;val<=_currentValue;val+=_ticksStep)
        drawLine(painter, getDegFromValue(val), beg, end);
    drawLine(painter, getDegFromValue(_currentValue), beg, end);
}

void CGBar::drawLine(QPainter *painter, float angle, float beg, float end)
{
    QPointF lineBeg = _parent->point(beg, angle);
    QPointF lineEnd = _parent->point(end, angle);
    painter->drawLine(lineBeg,lineEnd);
}

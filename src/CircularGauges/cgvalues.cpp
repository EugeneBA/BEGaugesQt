#include "cgvalues.h"
#include"cgwidget.h"

CGValues::CGValues(CGWidget *parent) : CGScale(parent)
{
    _step = 10;
    _correctPos = false;
    _boldFont = false;
}


void CGValues::draw(QPainter*painter)
{
    float r = _parent->radius();

    QRectF rect = _parent->rect();

    QFont font(_parent->font());
    font.setPointSizeF(relToAbs(r,_rFontSize));
    font.setWeight(_boldFont?QFont::Bold:QFont::Normal);
    painter->setFont(font);

    painter->setPen(_color);
    for(float val = _minValue;val<=_maxValue;val+=_step)
    {
        float deg = getDegFromValue(val);
        QPointF pt = _parent->point(relToAbs(r, _rPos), deg);

        QString strVal = QString::number(val);
        QFontMetrics fMetrics = painter->fontMetrics();
        QSize sz = fMetrics.size( Qt::TextSingleLine, strVal );
        QRectF txtRect(QPointF(0,0), sz );        
        txtRect.moveCenter(pt);
        if(_correctPos)
            CGWidget::SetInRect(rect,txtRect);

        painter->drawText( txtRect, Qt::TextSingleLine, strVal );
    }
}

void CGValues::setStep(float step)
{
    _step = step;
}

void CGValues::setrFontSize(float rFontSize)
{
    _rFontSize = rFontSize;
    update();
}

void CGValues::setBoldFont(bool boldFont)
{
    _boldFont = boldFont;
    update();
}

void CGValues::setCorrectPos(bool correctPos)
{
    _correctPos = correctPos;
}

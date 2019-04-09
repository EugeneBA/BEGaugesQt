#include "cgtext.h"
#include"cgwidget.h"

CGText::CGText(CGWidget *parent) : CGItem(parent)
{

    mAngle = 90;
    _text = "X";
    _rFontSize = 12;
    _boldFont = true;
}

void CGText::draw(QPainter *painter)
{
    float r = _parent->radius();
    QFont font(_parent->font());
    font.setPointSizeF(rPosToPoints(r,_rFontSize));
    font.setWeight(_boldFont?QFont::Bold:QFont::Normal);
    painter->setFont(font);
    painter->setPen(QPen(_color));

    QPointF txtCenter = _parent->point(rPosToPoints(r,_rPos), mAngle);

    QFontMetrics fMetrics = painter->fontMetrics();
    QSize sz = fMetrics.size( Qt::TextSingleLine, _text );
    QRectF txtRect(QPointF(0,0), sz );
    txtRect.moveCenter(txtCenter);

    painter->drawText( txtRect, Qt::TextSingleLine,_text );
}

void CGText::setAngle(float a)
{
    mAngle = a;
    update();
}

float CGText::angle()
{
    return mAngle;
}

void CGText::setText(const QString &text, bool repaint)
{
    _text = text;
    if(repaint)
        update();
}

QString CGText::text()
{
    return _text;
}

void CGText::setrFontSize(float rFontSize)
{
    _rFontSize = rFontSize;
    update();
}

void CGText::setBoldFont(bool boldFont)
{
    _boldFont = boldFont;
    update();
}

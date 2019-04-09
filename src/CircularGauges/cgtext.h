#pragma once

#include "cgitem.h"

class CGText : public CGItem
{
    Q_OBJECT
public:
    explicit CGText(CGWidget *parent);
    virtual void draw(QPainter *);
    void setAngle(float);
    float angle();
    void setText(const QString &text, bool repaint = true);
    QString text();


    inline float rFontSize() {return _rFontSize;}
    void setrFontSize(float rFontSize);

    inline bool boldFont() {return _boldFont;}
    void setBoldFont(bool boldFont);

private:
    float mAngle;
    float _rFontSize;
    bool _boldFont;
    QString _text;
};

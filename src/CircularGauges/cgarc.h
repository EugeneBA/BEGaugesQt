#ifndef QCARC_H
#define QCARC_H

#include "cgscale.h"

class CGArc : public CGScale
{
    Q_OBJECT
public:
    explicit CGArc(CGWidget *parent);
    void draw(QPainter*);

    inline float rWidth() {return _rWidth;}
    void setrWidth(float rWidth);

protected:
    float _rWidth;
};

#endif // QCARC_H

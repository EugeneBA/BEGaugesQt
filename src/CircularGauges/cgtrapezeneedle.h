#pragma once

#include "cgneedle.h"


class CGTrapezeNeedle : public CGNeedle
{
    Q_OBJECT
public:
    explicit CGTrapezeNeedle(CGWidget *parent);
    virtual void draw(QPainter *);

    inline float aspect() {return _aspect;}
    void setAspect(float aspect);

private:
    float _aspect;
};

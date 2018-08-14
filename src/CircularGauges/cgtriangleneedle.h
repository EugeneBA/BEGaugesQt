#pragma once

#include "cgneedle.h"

class CGTriangleNeedle:public CGNeedle
{
    Q_OBJECT

public:
    explicit CGTriangleNeedle(CGWidget *parent);
    virtual void draw(QPainter *);
};

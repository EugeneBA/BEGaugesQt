#pragma once

#include "src/CircularGauges/cgwidget.h"
#include <QTime>

class CGTrapezeNeedle;
class CGTriangleNeedle;

class ClockWidget:public CGWidget
{
    Q_OBJECT
    public:
        explicit ClockWidget(QWidget *parent = nullptr);

        void setTime(QTime value);
        void setTime();

    private:
        CGTrapezeNeedle* _hourNeedle;
        CGTrapezeNeedle* _minuteNeedle;
        CGTriangleNeedle* _secondNeedle;

    public slots:
        void OnTimerEvent();
};


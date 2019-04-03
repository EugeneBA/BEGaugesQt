#pragma once

#include "src/CircularGauges/cgwidget.h"
#include <QTime>

class CGTrapezeNeedle;
class CGTicks;
class CGValues;

class VoltmeterWidget:public CGWidget
{
    Q_OBJECT
    public:
        explicit VoltmeterWidget(QWidget *parent = nullptr);

        void setTime(QTime value);
        void setTime();

        void setValue(float value);
        void setRange(float min, float max);

    private:
        CGTrapezeNeedle* _needle;
        CGTicks* _ticks;
        CGTicks* _bigTicks;
        CGValues* _vals;

    public slots:
        void OnTimerEvent();
};


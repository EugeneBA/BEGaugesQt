#pragma once

#include "src/CircularGauges/cgwidget.h"

class CGTrapezeNeedle;
class CGTicks;
class CGValues;
class CGText;

class ArrowMeterWidget:public CGWidget
{
    Q_OBJECT
    public:
        explicit ArrowMeterWidget(QWidget *parent = nullptr);

        void setValue(float value);
        void setRange(float min, float max);

    private:
        CGTrapezeNeedle* _needle;
        CGTicks* _ticks;
        CGTicks* _bigTicks;
        CGValues* _vals;
        CGText* _value;
        CGText* _mode;    
};


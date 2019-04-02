#pragma once

#include "src/CircularGauges/cgwidget.h"
#include <QTime>

class CGTrapezeNeedle;
class CGTriangleNeedle;

class VoltmeterWidget:public CGWidget
{
    Q_OBJECT
    public:
        explicit VoltmeterWidget(QWidget *parent = nullptr);

        void setTime(QTime value);
        void setTime();

    private:
        CGTrapezeNeedle* _hourNeedle;
        CGTrapezeNeedle* _minuteNeedle;
        CGTriangleNeedle* _secondNeedle;

    public slots:
        void OnTimerEvent();
};


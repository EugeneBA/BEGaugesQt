#include "clockwidget.h"
#include "src/CircularGauges/cgarc.h"
#include "src/CircularGauges/cgticks.h"
#include "src/CircularGauges/cgvalues.h"
#include "src/CircularGauges/cgtrapezeneedle.h"
#include "src/CircularGauges/cgtriangleneedle.h"

#include <QTimer>

ClockWidget::ClockWidget(QWidget *parent) : CGWidget(parent)
{
    _centerPos = CenterCenter;

    setWindowTitle("Simple clock");

    auto margins = contentsMargins();
    margins.setBottom(10);
    margins.setTop(10);
    margins.setLeft(10);
    margins.setRight(10);
    setContentsMargins(margins);

        auto _outArc = new CGArc(this);
        _outArc->setrPos(1);
        _outArc->setrWidth(10);
        _outArc->setDegreeRange(90,-270);
        _items.append(_outArc);

//        _inArc = new QCArc(this);
//        _inArc->setrPos(0.6f);
//        _inArc->setrWidth(2);
//        _inArc->setDegreeRange(180,0);
//        mItems.append(_inArc);

        auto _ticks = new CGTicks(this);
        _ticks->setrPos(0.97f);
        _ticks->setrLength(0.03f);
        _ticks->setDegreeRange(90,-270);

        _ticks->setValueRange(0,60);
        _ticks->setStep(1);
        _items.append(_ticks);

        auto _bigTicks = new CGTicks(this);
        _bigTicks->setrPos(0.95f);
        _bigTicks->setrLength(0.05f);
        _bigTicks->setrWidth(5);
        _bigTicks->setDegreeRange(90,-270);

        _bigTicks->setValueRange(0,12);
        _bigTicks->setStep(1);
        _items.append(_bigTicks);

//        _image = new QCImage(this);
//        _image->setrPos(0.73f);
//        _image->setPixmap(Helper::LoadPixmap("image101.svg",Helper::defIconSize()));
//        _image->setDefaultColor(Helper::gaugeIconColor());
//        _image->setBlinkedColor(Helper::gaugeBlinkingColor());
//        _image->setAngle(90);
//        mItems.append(_image);

        auto _vals = new CGValues(this);
        _vals->setrPos(0.85f);
        _vals->setDegreeRange(60,-270);
        _vals->setValueRange(1,12);
        _vals->setStep(1);
        _vals->setrFontSize(38);
        _items.append(_vals);


//        _labelValue = new QCLabel(this);
//        _labelValue->setrPos(0.30f);
//        _labelValue->setAngle(90);
//        _labelValue->setrFontSize(50);
//        mItems.append(_labelValue);

        _hourNeedle = new CGTrapezeNeedle(this);
        //_needle->setrPos(0.605f);
        _hourNeedle->setrLength(0.7f);
        _hourNeedle->setrWidth(9);
        _hourNeedle->setDegreeRange(90,-270);
        _hourNeedle->setValueRange(0,12);
        _hourNeedle->setColor(Qt::black);
        _items.append(_hourNeedle);

        _minuteNeedle = new CGTrapezeNeedle(this);
        //_needle->setrPos(0.605f);
        _minuteNeedle->setrLength(0.9f);
        _minuteNeedle->setrWidth(5);
        _minuteNeedle->setDegreeRange(90,-270);
        _minuteNeedle->setValueRange(0,60);
        _minuteNeedle->setColor(Qt::black);
        _items.append(_minuteNeedle);

        _secondNeedle = new CGTriangleNeedle(this);
        //_needle->setrPos(0.605f);
        _secondNeedle->setrLength(0.97f);
        _secondNeedle->setrWidth(5);
        _secondNeedle->setDegreeRange(90,-270);
        _secondNeedle->setValueRange(0,60);
        _secondNeedle->setColor(Qt::red);
        _items.append(_secondNeedle);

        setGaugeColor(Qt::black);
        setTime();

        QTimer *timer = new QTimer(this);
        timer->setInterval(500);
        connect(timer, SIGNAL(timeout()), this, SLOT(OnTimerEvent()));
        timer->start();
}

void ClockWidget::setTime(QTime value)
{
    float hour = value.hour()%12+value.minute()/60.0f;
    _hourNeedle->setCurrentValue(hour);

    float minute = value.minute()+value.second()/60.0f;
    _minuteNeedle->setCurrentValue(minute);

    _secondNeedle->setCurrentValue(value.second());
}

void ClockWidget::setTime()
{
    setTime(QTime::currentTime());
}

void ClockWidget::OnTimerEvent()
{
    setTime();
}

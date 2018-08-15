#include "clockwidget.h"
#include "src/CircularGauges/cgarc.h"
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
        mItems.append(_outArc);

//        _inArc = new QCArc(this);
//        _inArc->setrPos(0.6f);
//        _inArc->setrWidth(2);
//        _inArc->setDegreeRange(180,0);
//        mItems.append(_inArc);

//        _ticks = new QCTicks(this);
//        _ticks->setrPos(0.95f);
//        _ticks->setrLength(0.05f);
//        _ticks->setDegreeRange(180,0);

//        _ticks->setValueRange(0,30);
//        _ticks->setStep(5);
//        mItems.append(_ticks);

//        _image = new QCImage(this);
//        _image->setrPos(0.73f);
//        _image->setPixmap(Helper::LoadPixmap("image101.svg",Helper::defIconSize()));
//        _image->setDefaultColor(Helper::gaugeIconColor());
//        _image->setBlinkedColor(Helper::gaugeBlinkingColor());
//        _image->setAngle(90);
//        mItems.append(_image);

//        _vals = new QCValues(this);
//        _vals->setrPos(0.80f);
//        _vals->setDegreeRange(180,0);
//        _vals->setValueRange(0,30);
//        _vals->setStep(10);
//        _vals->setrFontSize(38);
//        mItems.append(_vals);


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
        mItems.append(_hourNeedle);

        _minuteNeedle = new CGTrapezeNeedle(this);
        //_needle->setrPos(0.605f);
        _minuteNeedle->setrLength(0.9f);
        _minuteNeedle->setrWidth(5);
        _minuteNeedle->setDegreeRange(90,-270);
        _minuteNeedle->setValueRange(0,60);
        _minuteNeedle->setColor(Qt::black);
        mItems.append(_minuteNeedle);

        _secondNeedle = new CGTriangleNeedle(this);
        //_needle->setrPos(0.605f);
        _secondNeedle->setrLength(0.95f);
        _secondNeedle->setrWidth(5);
        _secondNeedle->setDegreeRange(90,-270);
        _secondNeedle->setValueRange(0,60);
        _secondNeedle->setColor(Qt::red);
        mItems.append(_secondNeedle);

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

#include "voltmeterwidget.h"
#include "src/CircularGauges/cgarc.h"
#include "src/CircularGauges/cgticks.h"
#include "src/CircularGauges/cgvalues.h"
#include "src/CircularGauges/cgtrapezeneedle.h"
#include "src/CircularGauges/cgtriangleneedle.h"

#include <QTimer>

VoltmeterWidget::VoltmeterWidget(QWidget *parent) : CGWidget(parent)
{
    _centerPos = BottomCenter;

    setWindowTitle("Voltmeter");

    auto margins = contentsMargins();
    margins.setBottom(5);
    margins.setTop(10);
    margins.setLeft(10);
    margins.setRight(10);
    setContentsMargins(margins);

    float minAngle = 150;
    float maxAngle = 30;

    auto _outArc = new CGArc(this);
    _outArc->setrPos(1);
    _outArc->setrWidth(8);
    _outArc->setDegreeRange(minAngle,maxAngle);
    mItems.append(_outArc);

    _ticks = new CGTicks(this);
    _ticks->setrPos(0.96f);
    _ticks->setrLength(0.04f);
    _ticks->setDegreeRange(minAngle,maxAngle);
    mItems.append(_ticks);

    _bigTicks = new CGTicks(this);
    _bigTicks->setrPos(0.925f);
    _bigTicks->setrLength(0.075f);
    _bigTicks->setrWidth(4);
    _bigTicks->setDegreeRange(minAngle,maxAngle);
    mItems.append(_bigTicks);

    //        _image = new QCImage(this);
    //        _image->setrPos(0.73f);
    //        _image->setPixmap(Helper::LoadPixmap("image101.svg",Helper::defIconSize()));
    //        _image->setDefaultColor(Helper::gaugeIconColor());
    //        _image->setBlinkedColor(Helper::gaugeBlinkingColor());
    //        _image->setAngle(90);
    //        mItems.append(_image);

    _vals = new CGValues(this);
    _vals->setrPos(1.07f);
    _vals->setDegreeRange(minAngle,maxAngle);
    _vals->setrFontSize(32);
    mItems.append(_vals);


    //        _labelValue = new QCLabel(this);
    //        _labelValue->setrPos(0.30f);
    //        _labelValue->setAngle(90);
    //        _labelValue->setrFontSize(50);
    //        mItems.append(_labelValue);

    _needle = new CGTrapezeNeedle(this);
    //_needle->setrPos(0.605f);
    _needle->setrLength(0.95f);
    _needle->setrWidth(5);
    _needle->setDegreeRange(minAngle,maxAngle);
    _needle->setColor(Qt::black);
    mItems.append(_needle);

    setRange(0, 60);
    setGaugeColor(Qt::black);
    setTime();

    QTimer *timer = new QTimer(this);
    timer->setInterval(500);
    connect(timer, SIGNAL(timeout()), this, SLOT(OnTimerEvent()));
    timer->start();
}

void VoltmeterWidget::setValue(float value)
{
    _needle->setCurrentValue(value);
}

void VoltmeterWidget::setRange(float min, float max)
{
    float N = 4;
    float delta = (max-min)/N;

    _ticks->setValueRange(min,max);
    _ticks->setStep(delta/5.0f);
    _bigTicks->setValueRange(min,max);
    _bigTicks->setStep(delta);
    _vals->setValueRange(min,max);
    _vals->setStep(delta);
    _needle->setValueRange(min,max);
}

void VoltmeterWidget::setTime(QTime value)
{
    _needle->setCurrentValue(value.second());
}

void VoltmeterWidget::setTime()
{
    setTime(QTime::currentTime());
}

void VoltmeterWidget::OnTimerEvent()
{
    setTime();
}

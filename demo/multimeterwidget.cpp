#include "multimeterwidget.h"
#include "ui_multimeterwidget.h"

#include "QtCore/qmath.h"
#include "QTimer"
#include "QDir"
#include "QPixmap"
#include "QString"

MultimeterWidget::MultimeterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultimeterWidget)
{
    ui->setupUi(this);

    setWindowTitle("Multimeter");
    setStyleSheet(QString::fromUtf8("QFrame#_frameScreen { background: white }"));
    ui->_btnU2->setChecked(true);
    _startTime = QDateTime::currentDateTime();
    QTimer *timer = new QTimer(this);
    timer->setInterval(200);
    connect(timer, SIGNAL(timeout()), this, SLOT(OnTimerEvent()));
    timer->start();

    _filenum = 0;
}



void MultimeterWidget::OnTimerEvent()
{
    auto curentTime = QDateTime::currentDateTime();

    double t = _startTime.msecsTo(curentTime)*0.001;

    const double f = 0.05;
    double val = qSin(2*M_PI*f*t);
    //if(qFabs(val)<0.1)
    //    val = 0.0;

    if(ui->_btnR2k->isChecked()||ui->_btnR200->isChecked())
    {
        val+=1.0;
        val*=1.05;
    }
    else
    {
        val*=2.1;
    }

    if(ui->_btnI200m->isChecked()||ui->_btnU200m->isChecked()||ui->_btnR200->isChecked())
    {
        val*=100;
    }


    ui->_meter->setValue(val);

    _filenum++;
    if(_filenum%3!=0)
        return;

    const QString format = "png";
    QString path = QDir::currentPath();
    path += QString("/screen")+QString::number(_filenum).rightJustified(6,'0')+"." + format;



     auto originalPixmap = QPixmap::grabWindow(winId());
       originalPixmap.save(path,format.toAscii());
}

MultimeterWidget::~MultimeterWidget()
{
    delete ui;
}

void MultimeterWidget::on__btnClose_clicked()
{
    close();
}

void MultimeterWidget::on__btnU2_toggled(bool checked)
{
    if(!checked)
        return;

    ui->_meter->setMode("V");
    ui->_meter->setRange(-2,2);

    //ui->_btnU2->setChecked(false);
    ui->_btnU200m->setChecked(false);
    ui->_btnI2->setChecked(false);
    ui->_btnI200m->setChecked(false);
    ui->_btnR2k->setChecked(false);
    ui->_btnR200->setChecked(false);
}

void MultimeterWidget::on__btnU200m_toggled(bool checked)
{
    if(!checked)
        return;

    ui->_meter->setMode("mV");
    ui->_meter->setRange(-200,200);

    ui->_btnU2->setChecked(false);
    //ui->_btnU200m->setChecked(false);
    ui->_btnI2->setChecked(false);
    ui->_btnI200m->setChecked(false);
    ui->_btnR2k->setChecked(false);
    ui->_btnR200->setChecked(false);
}

void MultimeterWidget::on__btnI2_toggled(bool checked)
{
    if(!checked)
        return;

    ui->_meter->setMode("A");
    ui->_meter->setRange(-2,2);

    ui->_btnU2->setChecked(false);
    ui->_btnU200m->setChecked(false);
    //ui->_btnI2->setChecked(false);
    ui->_btnI200m->setChecked(false);
    ui->_btnR2k->setChecked(false);
    ui->_btnR200->setChecked(false);
}

void MultimeterWidget::on__btnI200m_toggled(bool checked)
{
    if(!checked)
        return;

    ui->_meter->setMode("mA");
    ui->_meter->setRange(-200,200);

    ui->_btnU2->setChecked(false);
    ui->_btnU200m->setChecked(false);
    ui->_btnI2->setChecked(false);
    //ui->_btnI200m->setChecked(false);
    ui->_btnR2k->setChecked(false);
    ui->_btnR200->setChecked(false);
}

void MultimeterWidget::on__btnR2k_toggled(bool checked)
{
    if(!checked)
        return;

    ui->_meter->setMode("kOm");
    ui->_meter->setRange(0,2);

    ui->_btnU2->setChecked(false);
    ui->_btnU200m->setChecked(false);
    ui->_btnI2->setChecked(false);
    ui->_btnI200m->setChecked(false);
    //ui->_btnR2k->setChecked(false);
    ui->_btnR200->setChecked(false);
}

void MultimeterWidget::on__btnR200_toggled(bool checked)
{
    if(!checked)
        return;

    ui->_meter->setMode("Om");
    ui->_meter->setRange(0,200);

    ui->_btnU2->setChecked(false);
    ui->_btnU200m->setChecked(false);
    ui->_btnI2->setChecked(false);
    ui->_btnI200m->setChecked(false);
    ui->_btnR2k->setChecked(false);
    //ui->_btnR200->setChecked(false);
}

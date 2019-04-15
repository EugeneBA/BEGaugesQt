#include "multimeterwidget.h"
#include "ui_multimeterwidget.h"

#include "QtCore/qmath.h"
#include "QTimer"

MultimeterWidget::MultimeterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultimeterWidget)
{
    ui->setupUi(this);

    setWindowTitle("Multimeter");

    _startTime = QDateTime::currentDateTime();
    QTimer *timer = new QTimer(this);
    timer->setInterval(200);
    connect(timer, SIGNAL(timeout()), this, SLOT(OnTimerEvent()));
    timer->start();
}

void MultimeterWidget::OnTimerEvent()
{
    auto curentTime = QDateTime::currentDateTime();

    double t = _startTime.msecsTo(curentTime)*0.001;

    const double f = 0.05;
    double val = qSin(2*M_PI*f*t);
    if(qFabs(val)<0.1)
        val = 0.0;

    if(ui->_btnR2k->isChecked()||ui->_btnR200->isChecked())
        val+=1.0;


    ui->_meter->setValue(val*100);
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

}

void MultimeterWidget::on__btnU200m_toggled(bool checked)
{

}

void MultimeterWidget::on__btnI2_toggled(bool checked)
{

}

void MultimeterWidget::on__btnI200m_toggled(bool checked)
{

}

void MultimeterWidget::on__btnR2k_toggled(bool checked)
{

}

void MultimeterWidget::on__btnR200_toggled(bool checked)
{

}

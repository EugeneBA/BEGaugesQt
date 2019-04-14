#include "multimeterwidget.h"
#include "ui_multimeterwidget.h"

MultimeterWidget::MultimeterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultimeterWidget)
{
    ui->setupUi(this);
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

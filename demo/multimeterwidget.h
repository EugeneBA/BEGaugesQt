#ifndef MULTIMETERWIDGET_H
#define MULTIMETERWIDGET_H

#include <QWidget>
#include <QDateTime>


namespace Ui {
class MultimeterWidget;
}

class MultimeterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MultimeterWidget(QWidget *parent = nullptr);
    ~MultimeterWidget();


private slots:
    void OnTimerEvent();

    void on__btnClose_clicked();

    void on__btnU2_toggled(bool checked);

    void on__btnU200m_toggled(bool checked);

    void on__btnI2_toggled(bool checked);

    void on__btnI200m_toggled(bool checked);

    void on__btnR2k_toggled(bool checked);

    void on__btnR200_toggled(bool checked);

private:
    Ui::MultimeterWidget *ui;
    QDateTime _startTime;
};

#endif // MULTIMETERWIDGET_H

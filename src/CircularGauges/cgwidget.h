#pragma once

#include <QColor>
#include <QWidget>

#include "cgitem.h"

enum EnumCenterPos
{
    CenterLeft,
    CenterCenter,
    CenterRight,
    BottomLeft,
    BottomCenter,
    BottomRight
};

class CGWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CGWidget(QWidget *parent = nullptr);
    float radius();
    float minAngle();
    float maxAngle();

    QPointF center();
    QPointF point(float rpos, float deg);
    QRectF gaugeRect();
    QSizeF gaugeSize();
    QRectF gaugeFullRect();

    static double DegreesToRadians(double deg);
    static double RadiansToDegrees(double rad);
    static void SetInRect(const QRectF& out,QRectF& in);

protected:
    virtual QSize minimumSizeHint() const;

    void addItem(CGItem* item, float position);
    int removeItem(CGItem* item);
    QList <CGItem*> items();
    QList <CGItem*> mItems;

    EnumCenterPos _centerPos;    

signals:

public slots:

private:    
    void paintEvent(QPaintEvent *);

protected:
    //gauge color
    QColor _gaugeColor;
    QColor gaugeColor();
    virtual void setGaugeColor(const QColor &gaugeColor);    
};

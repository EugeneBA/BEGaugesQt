#pragma once

#include <QColor>
#include <QWidget>

#include "cgitem.h"
#include "qwitem.h"
#include "enumcenterpos.h"

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
    static QPointF getCenterOriginLocation(QRectF rect, EnumCenterPos centerOrigin);

    inline EnumCenterPos centerOrigin(){return _centerPos;}

protected:
    //virtual QSize minimumSizeHint() const;
    //virtual QSize sizeHint() const;
    //virtual int heightForWidth(int w) const;
    //virtual bool hasHeightForWidth() const {return true;}

    void addItem(CGItem* item, float position);
    int removeItem(CGItem* item);
    QList <CGItem*> _cgItems;

    void addItem(QWItem* item);
    int removeItem(QWItem* item);
    QList <QWItem*> _qwItems;

    QWItem* addQWidget(QWidget* widget);

    EnumCenterPos _centerPos;

    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);


signals:
public slots:

};

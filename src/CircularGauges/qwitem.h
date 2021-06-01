#pragma once

#include <QObject>
#include <QWidget>
#include "enumcenterpos.h"

class CGWidget;

class QWItem : public QObject
{
    Q_OBJECT
public:
    explicit QWItem(CGWidget *parent, QWidget* widget = nullptr);

    void setrLoc(QPointF rloc);
    inline QPointF rLoc(){return _rLoc;}

    void setrSize(QSizeF rsize);
    inline QSizeF rSize(){return _rSize;}

    void setCenterOrigin(EnumCenterPos origin);
    inline EnumCenterPos centerOrigin(){return _centerOrigin;}

    void updateSize();
    void updateLoc();

protected:
    //static QRectF adjustRect(const QRectF& rect, float rpos);
    static float relToAbs(float basis, float relValue);
    static QSizeF relToAbs(QSizeF basis, QSizeF relValue);
    static QPointF relToAbs(QSizeF basis, QPointF relValue);

    CGWidget* _parent;

    QPointF _rLoc;
    QSizeF _rSize;

    EnumCenterPos _centerOrigin;



    QWidget* _widget;
};

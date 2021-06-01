#include "qwitem.h"
#include<qmath.h>
#include"cgwidget.h"


QWItem::QWItem(CGWidget *parent, QWidget* widget) :
    QObject(parent)
{
    _parent = parent;
    _widget = widget;
    _centerOrigin = EnumCenterPos::BottomCenter;
    _rLoc = QPointF(0,0);
    _rSize = QSizeF(50,50);
}

void QWItem::setrLoc(QPointF rloc)
{
    _rLoc = rloc;
}

void QWItem::setrSize(QSizeF rsize)
{
    _rSize = rsize;
    updateSize();
}

void QWItem::setCenterOrigin(EnumCenterPos origin)
{
    _centerOrigin = origin;
}

void QWItem::updateSize()
{
  if(_widget==nullptr)
      return;

  auto parent_size = _parent->gaugeRect().size();
  auto widget_rect = _widget->geometry();
  auto new_size = relToAbs(parent_size,_rSize);
  _widget->setGeometry(widget_rect.x(),widget_rect.y(),new_size.width(),new_size.height());
}

void QWItem::updateLoc()
{
    auto parent_rect = _parent->gaugeRect();
    auto widget_rect = _widget->geometry();

    auto parent_center = CGWidget::getCenterOriginLocation(parent_rect, _parent->centerOrigin());
    auto parent_centerShift = CGWidget::getCenterOriginLocation(QRectF(0,0,parent_rect.width(),parent_rect.height()), _centerOrigin);
    auto widget_centerShift = CGWidget::getCenterOriginLocation(QRectF(0,0,widget_rect.width(),widget_rect.height()), _centerOrigin);

    auto new_loc = relToAbs(parent_rect.size(), _rLoc);

    new_loc = parent_center + new_loc - widget_centerShift;

    _widget->setGeometry(new_loc.x(), new_loc.y(), widget_rect.width(), widget_rect.height());
}

//QRectF CGItem::adjustRect(const QRectF& rect, float rpos)
//{
//    float radius = _parent->radius();
//    float offset =   radius - rPosToPoints(radius,rpos);
//    QRectF tmpRect = rect.adjusted(offset,offset,-offset,-offset);
//    return tmpRect;
//}

float QWItem::relToAbs(float basis, float relValue)
{
    //if(relValue<=0)
    //    return 0.0f;
    if(qAbs(relValue)>1.0)
        return relValue;

    return basis*relValue;
}

QSizeF QWItem::relToAbs(QSizeF basis, QSizeF relValue)
{
    return QSizeF(relToAbs(basis.width(),relValue.width()), relToAbs(basis.height(),relValue.height()));
}

QPointF QWItem::relToAbs(QSizeF basis, QPointF relValue)
{
    return QPointF(relToAbs(basis.width(),relValue.x()), relToAbs(basis.height(),relValue.y()));
}

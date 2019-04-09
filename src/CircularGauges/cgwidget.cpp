#include "cgwidget.h"
#include "qmath.h"

CGWidget::CGWidget(QWidget *parent) : QWidget(parent)
{
    setFocusPolicy(Qt::FocusPolicy::NoFocus);
    _centerPos = EnumCenterPos::CenterCenter;
    setContentsMargins(5,5,5,5);
}

float CGWidget::minAngle()
{
    float angle = 0;
    switch (_centerPos)
    {
    case EnumCenterPos::CenterLeft:
        angle = 90;
        break;
    case EnumCenterPos::CenterRight:
        angle = 270;
        break;

    case EnumCenterPos::BottomLeft:
        angle = 90;
        break;
    case EnumCenterPos::BottomRight:
        angle = 270;
        break;
    case EnumCenterPos::BottomCenter:
        angle = 180;
        break;
    case EnumCenterPos::CenterCenter:
    default:
        angle = 270;
        break;
    }

    return angle;
}

float CGWidget::maxAngle()
{
    float angle = 0;
    switch (_centerPos)
    {
    case EnumCenterPos::CenterLeft:
        angle = -90;
        break;
    case EnumCenterPos::CenterRight:
        angle = 90;
        break;

    case EnumCenterPos::BottomLeft:
        angle = 0;
        break;
    case EnumCenterPos::BottomRight:
        angle = 90;
        break;
    case EnumCenterPos::BottomCenter:
        angle = 0;
        break;

    default:
        angle = -90;
        break;
    }

    return angle;
}

float CGWidget::radius()
{
    QSizeF size = gaugeSize();

    switch (_centerPos)
    {
    case EnumCenterPos::CenterCenter:
        return size.height()*0.5;

    case EnumCenterPos::BottomCenter:
        return size.height();

    default:
        return size.width();
    }
}

QPointF CGWidget::center()
{
    QRectF wrect = contentsRect();
    //wrect.adjust(_padding,_padding,-_padding,-_padding);
    QPointF center = wrect.center();
    switch (_centerPos)
    {
    case EnumCenterPos::CenterLeft:
        center.setX(wrect.left());
        return center;
    case EnumCenterPos::CenterRight:
        center.setX(wrect.right());
        return center;

    case EnumCenterPos::BottomLeft:
        return wrect.bottomLeft();
    case EnumCenterPos::BottomRight:
        return wrect.bottomRight();
    case EnumCenterPos::BottomCenter:
        center.setY(wrect.bottom());
        return center;

    default:
        return center;
    }
}

QPointF CGWidget::point(float rpos, float deg)
{
    //Q_ASSERT(rpos>=0);
    float rx=cos(DegreesToRadians(deg))*rpos;
    float ry=-sin(DegreesToRadians(deg))*rpos;
    QPointF rpt = QPointF(rx,ry);

    return center()+rpt;
}

QRectF CGWidget::gaugeRect()
{
    QRectF res = gaugeFullRect();


    switch (_centerPos)
    {
    case EnumCenterPos::CenterLeft:
        res.adjust(res.width()*0.5,0,0,0);
        break;
    case EnumCenterPos::CenterRight:
        res.setWidth(res.width()*0.5);
        break;

    case EnumCenterPos::BottomLeft:
        res.adjust(res.width()*0.5,0,0,-res.height()*0.5);
        break;
    case EnumCenterPos::BottomRight:
        res.setWidth(res.width()*0.5);
        res.setHeight(res.height()*0.5);
        break;
    case EnumCenterPos::BottomCenter:
        res.setHeight(res.height()*0.5);
        break;

    case EnumCenterPos::CenterCenter:
    default:
        break;
    }
    return res;
}

QRectF CGWidget::gaugeFullRect()
{
    QSizeF gsize = gaugeSize();
    QRectF res;
    switch (_centerPos)
    {
    case EnumCenterPos::CenterLeft:
    case EnumCenterPos::CenterRight:
        res = QRectF(0,0,gsize.width()*2,gsize.height());        
        break;

    case EnumCenterPos::BottomLeft:
    case EnumCenterPos::BottomRight:
        res = QRectF(0,0,gsize.width()*2,gsize.height()*2);
        break;

    case EnumCenterPos::BottomCenter:
        res = QRectF(0,0,gsize.width(),gsize.height()*2);        
        break;

     default:
        res = QRectF(0,0,gsize.width(),gsize.height());
        break;
    }
    res.moveCenter(center());
    return res;
}

QSizeF CGWidget::gaugeSize()
{
    QSize size = contentsRect().size();
    float w = size.width();
    float h = size.height();

    float r;
    switch (_centerPos)
    {
    case EnumCenterPos::CenterLeft:
    case EnumCenterPos::CenterRight:
        r = qMin(w*2,h);
        return QSizeF(r*0.5,r);

    case EnumCenterPos::BottomCenter:
        r = qMin(w,2*h);
        return QSizeF(r,r*0.5);

    default:
        r = qMin(w,h);
        return QSizeF(r,r);
    }
}

double CGWidget::DegreesToRadians(double deg)
{
    return deg * M_PI / 180 ;
}

double CGWidget::RadiansToDegrees(double rad)
{
    return rad * 180  / M_PI ;
}

QSize CGWidget::minimumSizeHint() const
{
    auto size = geometry().size();
    auto h = size.height();
    switch (_centerPos)
    {
    case EnumCenterPos::CenterLeft:
    case EnumCenterPos::CenterRight:
        size.setWidth(qMax(h/2,15));
        break;

    case EnumCenterPos::BottomCenter:
        size.setWidth(qMax(h*2,15));
        break;

    default:
        size.setWidth(qMax(h,15));
    }
 
    return size;
}

void CGWidget::addItem(CGItem *item,float position)
{
    // takes parentship of the item
    item->setParent(this);
    item->setrPos(position);
    _items.append(item);
}

int CGWidget::removeItem(CGItem *item)
{
    return _items.removeAll(item);
}

QList<CGItem *> CGWidget::items()
{
    return _items;
}

void CGWidget::paintEvent(QPaintEvent* /*paintEvt*/)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    foreach (CGItem * item, _items)
    {
        item->draw(&painter);
    }


    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidthF(1);
    painter.setPen(pen);
    //painter.drawRect(gaugeRect());
    //painter.drawRect(rect());
}

QColor CGWidget::gaugeColor()
{
    return _gaugeColor;
}

void CGWidget::setGaugeColor(const QColor &gaugeColor)
{
    _gaugeColor = gaugeColor;
}

void CGWidget::SetInRect(const QRectF &out, QRectF &in)
{
 if(out.contains(in))
     return;

 if(in.top()<out.top())
     in.moveTop(out.top());

 if(in.bottom()>out.bottom())
     in.moveBottom(out.bottom());

 if(in.left()<out.left())
     in.moveLeft(out.left());

 if(in.right()>out.right())
     in.moveRight(out.right());
}


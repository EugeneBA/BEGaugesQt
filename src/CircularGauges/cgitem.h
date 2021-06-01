#pragma once

#include <QObject>
#include <QPainter>
#include <QWidget>

class CGWidget;

class CGItem : public QObject
{
    Q_OBJECT
public:
    explicit CGItem(CGWidget *parent);

    virtual void draw(QPainter *) = 0;

    void setrPos(float rpos);
    inline float rPos(){return _rPos;}
    QRectF rect();
    enum Error{InvalidValueRange};

    inline QColor color(){return _color;}
    void setColor(const QColor& color);

protected:
    QRectF adjustRect(const QRectF& rect, float rpos);
    float relToAbs(float basis, float relValue);

    void update();

    CGWidget* _parent;
    float _rPos;

    QColor _color;

private:
    QRectF mRect;        
};

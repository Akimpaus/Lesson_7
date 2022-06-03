#include "drawitem.h"
#include <QRandomGenerator>


DrawItem::DrawItem(QObject *parent, const Type type) :
    QObject(parent),
    QGraphicsItem(),
    m_is_moves(false),
    m_type(type)
{
}

DrawItem::~DrawItem()
{

}

const QColor &DrawItem::getColor() const
{
    return m_color;
}

void DrawItem::setColor(const QColor &color)
{
    m_color = color;
}

QRectF DrawItem::boundingRect() const
{
    return QRectF (-30,-30,60,60);
}

void DrawItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(m_color);

    switch (m_type)
    {
    case Type::Rect:
        painter->drawRect(boundingRect());
    break;
    case Type::Elips:
        painter->drawEllipse(boundingRect());
    break;
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void DrawItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_is_moves)
        this->setPos(mapToScene(event->pos()));
}

void DrawItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
    {
        m_is_moves = true;
        this->setCursor(QCursor(Qt::ClosedHandCursor));
    }
}

void DrawItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_is_moves = false;
    this->setCursor(QCursor(Qt::ArrowCursor));
    if (event->button() == Qt::MouseButton::RightButton)
        delete this;
    else if (event->button() == Qt::MouseButton::LeftButton)
         m_is_moves = false;
}

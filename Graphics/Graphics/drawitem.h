#ifndef DRAWITEM_H
#define DRAWITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QRandomGenerator>

class DrawItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    enum Type
    {
        Rect,
        Elips
    };

    explicit DrawItem(QObject *parent = 0, const Type type = Type::Rect);

    ~DrawItem();

    const QColor& getColor() const;

    void setColor(const QColor& color);

signals:

private:

    bool m_is_moves;
    Type m_type;
    QColor m_color;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
};

#endif // MOVEITEM\_H

#include "mainwindow.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDebug>

static QColor getRandomColor()
{
    quint8 R = QRandomGenerator::global()->bounded(255);
    quint8 G = QRandomGenerator::global()->bounded(255);
    quint8 B = QRandomGenerator::global()->bounded(255);
    return QColor(R,G,B);
}

MainWindow::MainWindow(QWidget *parent) :
    QGraphicsView(parent),
    m_counter(0),
    m_is_rotates(false)
{
    m_scence = new QGraphicsScene(this);
    setScene(m_scence);
}

MainWindow::~MainWindow()
{
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
    {
        auto got_item = itemAt(event->pos());
        if(got_item == nullptr)
        {
            auto item = new DrawItem(this, static_cast<DrawItem::Type>(m_counter % 2));
            m_counter++;
            item->setPos(mapToScene(event->pos()));
            item->setColor(getRandomColor());
            m_scence->addItem(item);
        }
    }
    else if (event->button() == Qt::MouseButton::MiddleButton)
        m_is_rotates = true;
    return QGraphicsView::mousePressEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::MiddleButton)
        m_is_rotates = false;
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    constexpr float scale_factor = 1.15;
    constexpr float rotate_factor = 1;
    const float delta = event->angleDelta().y();
    if(m_is_rotates)
    {
        QPointF pos = event->position();
        auto got_item = itemAt(QPoint(pos.x(), pos.y()));
        if(got_item != nullptr)
            got_item->setRotation(got_item->rotation() + delta * rotate_factor);
    }
    else
    {
        if(delta > 0)
            scale(scale_factor, scale_factor);
        else
            scale(1.0 / scale_factor, 1.0 / scale_factor);
    }
}

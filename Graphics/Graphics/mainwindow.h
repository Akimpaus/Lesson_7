#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include "drawitem.h"


class MainWindow : public QGraphicsView
{

Q_OBJECT

public:

MainWindow(QWidget *parent = 0);

~MainWindow();

private:

QGraphicsView *m_view;
QGraphicsScene *m_scence;
size_t m_counter;
bool m_is_rotates;

void mousePressEvent(QMouseEvent *event) override;

void mouseReleaseEvent(QMouseEvent *event) override;

void wheelEvent(QWheelEvent *event) override;

protected:

private slots:

};


#endif // MAINWINDOW_H

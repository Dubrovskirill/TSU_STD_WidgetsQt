
#include <QSize>
#include <QTimerEvent>

#include "area.h"

Area::Area(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(QSize (300, 200));
    myLine = new MyLine(80, 100, 50);
    myRect = new MyRect(220, 100, 50);
    alpha = 0;
}

void Area::showEvent(QShowEvent *) {
    myTimer = startTimer(50);
}

void Area::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(Qt::red);
    myLine->move(alpha, &painter);
    myRect->move(alpha * (-0.5), &painter);
}

void Area::timerEvent(QTimerEvent *event) {
    if(event->timerId() == myTimer) {
        alpha = alpha + 0.2;
        update();
    } else {
        QWidget::timerEvent(event);
    }
}

void Area::hideEvent(QHideEvent *) {
    killTimer(myTimer);
}

Area::~Area() {
    delete myLine;
    delete myRect;
}

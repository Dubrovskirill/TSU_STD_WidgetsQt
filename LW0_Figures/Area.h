
#ifndef AREA_H
#define AREA_H

#include <QWidget>

#include "figura.h"

class Area : public QWidget {
    Q_OBJECT
public:
    explicit Area(QWidget *parent = nullptr);
    ~Area();
    MyLine *myLine = nullptr;
    MyRect *myRect = nullptr;
protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
private:
    int myTimer;
    float alpha;
};

#endif // AREA_H

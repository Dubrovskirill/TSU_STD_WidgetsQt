#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>

class Figura {
public:
    Figura(int x, int y, int halflen)
        :x(x), y(y), halflen(halflen)
    {}
    virtual ~Figura() = default;
    void move(float alpha, QPainter *painter);
protected:
    int x, y, halflen, dx, dy, r;
    virtual void draw(QPainter *painter) = 0;
};

class MyLine: public Figura {
public:
    MyLine(int x, int y, int halflen)
        :Figura(x, y, halflen)
    {}
protected:
    void draw(QPainter *painter) override;
};

class MyRect: public Figura {
public:
    MyRect(int x, int y, int halflen)
        :Figura(x, y, halflen)
    {}
protected:
    void draw(QPainter *painter) override;
};

#endif // FIGURA_H

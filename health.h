#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem{
public:
    Health();
    int getHealth();
    void decrease();
private:
    int health;
};

#endif // HEALTH_H

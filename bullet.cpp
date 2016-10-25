#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QList>

extern Game *game;

Bullet::Bullet()
{
    setRect(0, 0, 5, 25);
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem *> collidingEnemies = collidingItems();
    for(int i = 0;i < collidingEnemies.size();++i){
        if(typeid(*(collidingEnemies[i])) == typeid(Enemy)){

            game->score->increase();

            scene()->removeItem(collidingEnemies[i]);
            scene()->removeItem(this);
            delete collidingEnemies[i];
            delete this;
            qDebug() << "Delete both the bullet and the enemy";
            return;
        }
    }

    setPos(x(), y()-10);
    if(y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted...";
    }
}

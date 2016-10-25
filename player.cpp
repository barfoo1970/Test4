#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QDebug>
#include "player.h"
#include "bullet.h"
#include "enemy.h"

void Player::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:
        {
            int newX = x()-10 > 0 ? x()-10 : 0;
            setPos(newX, y());
            break;
        }
    case Qt::Key_Right:
        {
            int newX = x()+10 < scene()->width()-rect().width() ? x()+10 : scene()->width()-rect().width();

            // move the left border a little bit lefter
            newX = newX-1;

            setPos(newX, y());
            break;
        }
    case Qt::Key_Space:
        {
            Bullet *bullet = new Bullet();
            bullet->setPos(x(), y());
            scene()->addItem(bullet);
            break;
        }
    default:
        break;
    }
}

void Player::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}

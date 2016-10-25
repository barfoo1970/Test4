#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include "enemy.h"
#include "game.h"

extern const int SCENE_WIDTH, SCENE_HEIGHT;
extern Game *game;

Enemy::Enemy()
{
    //std::srand(std::time(0));
    int rectWidth = 100, rectHeight = 100;
    int widthRange = SCENE_WIDTH - rectWidth;
    int randomX = rand() % widthRange;
    setRect(randomX, 0, rectWidth, rectHeight);
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(80);
}

void Enemy::move()
{
    int newY = y() + 7;
    if(newY <= SCENE_HEIGHT)
        setPos(x(), newY);
    else{
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemy out of boudary, delete it";
    }

}

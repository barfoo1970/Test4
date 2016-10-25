#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "score.h"
#include "health.h"

class Game : public QGraphicsView{
public:
    Game(QWidget *parent = 0);
    QGraphicsScene *scene;
    Player *player;
    //Bullet *bullet;
    //Enemy *enemy;
    Score *score;
    Health *health;
};

#endif // GAME_H

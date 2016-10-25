#include "game.h"
#include <QTimer>
#include <QObject>

extern const int SCENE_WIDTH = 800, SCENE_HEIGHT = 600;

Game::Game(QWidget *parent):QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    player = new Player();
    player->setRect(0, 0, 100, 100);
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(SCENE_WIDTH, SCENE_HEIGHT);
    scene->setSceneRect(0, 0, SCENE_WIDTH, SCENE_WIDTH);
    player->setPos((width() - player->rect().width())/2, height() - player->rect().height());

    score = new Score();
    score->setPos(0, 0);
    health = new Health();
    health->setPos(x(), y() + 20);
    scene->addItem(score);
    scene->addItem(health);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(4000);
}

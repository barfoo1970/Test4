#include "health.h"
#include <QFont>

Health::Health()
{
    health = 3;
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 12));
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}

void Health::decrease()
{
    --health;
    setPlainText(QString("Health: ") + QString::number(health));
}

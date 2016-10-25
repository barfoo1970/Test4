#include "score.h"
#include <QFont>

Score::Score()
{
    score = 0;
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 12));
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}

void Score::increase()
{
    ++score;
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::decrease()
{
    --score;
    setPlainText(QString("Score: ") + QString::number(score));
}

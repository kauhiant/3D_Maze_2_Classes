#include "Castle.h"

Castle::Castle(int level):level(level)
{
    //setSpeed(0);
    setHP(500*level);
    //setPower(0);
    //setAttackDistance(0);
}

Castle::~Castle()
{
    //dtor
}

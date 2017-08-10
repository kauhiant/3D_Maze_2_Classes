#include "Arrow.h"

Arrow::Arrow(int position)
{
    setValue(position);
    setSpeed(5);
    setHP(100);
    setPower(10);
    setAttackDistance(100);
}

Arrow::~Arrow()
{
    //dtor
}

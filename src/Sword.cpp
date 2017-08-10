#include "Sword.h"

Sword::Sword(int position)
{
    setHP(100);
    setPower(10);
    setSpeed(10);
    setValue(position);
}

Sword::~Sword()
{
    //dtor
}

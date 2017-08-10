#include "Castle.h"

Castle::Castle(int position, int level):level(level)
{
    setHP(500*level);
    setValue(position);
}

Castle::~Castle()
{
    //dtor
}

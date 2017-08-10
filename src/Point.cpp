#include "Point.h"

void Point::setValue(int val) {
    value = val;
    if(val < 0) value = 0;
}

int Point::distance(Point* other){
    return (other->value < this->value)?
            this->value-other->value :
            other->value-this->value;
}

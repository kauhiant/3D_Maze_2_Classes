#include "Point.h"

void Point::setValue(int val) {
    value = val;
    if(val < 0) value = 0;
}
void Point::setSpeed(int val) {
    speed = val;
    if(val < 0) speed = 0;
}
int Point::distance(Point* other){
    return (other->value < this->value)?
            this->value-other->value :
            other->value-this->value;
}
void Point::moveTo(const Point* target){
    if(target->value < this->value){
        this->value -= speed;
        if(target->value > this->value)
            this->value = target->value;
    }
    else if(target->value > this->value){
        this->value += speed;
        if(target->value < this->value)
            this->value = target->value;
    }
}

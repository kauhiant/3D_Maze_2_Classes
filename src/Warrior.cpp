#include "Warrior.h"

void Warrior::setSpeed(int val) {
    speed = val;
    if(val < 0) speed = 0;
}

void Warrior::setHP(int val){
    if(val < 0)
        HP = 0;
    else
        HP = val;
}

void Warrior::setPower(int val){
    if(val < 0)
        power = 0;
    else
        power = val;
}

void Warrior::setAttackDistance(int val){
    if(val < 0)
        attackDistance = 0;
    else
        attackDistance = val;
}
//覺得可以改更好
void Warrior::moveTo(Point* &target){
    if(distance(target) <= attackDistance)
        return;

    if(target->getValue() < this->value){
        this->value -= speed;
        if(target->getValue() > this->value)
            this->value = target->getValue();
    }
    else if(target->getValue() > this->value){
        this->value += speed;
        if(target->getValue() < this->value)
            this->value = target->getValue();
    }
}

void Warrior::beAttack(int harm){
    HP -= harm;
    if(HP < 0)
        this->beKill();
}

void Warrior::attack(Warrior* obj){
    if(this->distance(obj) <= attackDistance){
        obj->beAttack(this->power);
    }
}

void Warrior::beKill(){
    HP = 0;
    power = 0;
    attackDistance = 0;
    speed = 0;
}




#include "Warrior.h"

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
  //  value = 0;
    speed = 0;
}

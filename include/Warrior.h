#ifndef WARRIOR_H
#define WARRIOR_H

#include <Point.h>


class Warrior : public Point
{
    public:
        Warrior():HP(0),power(0),attackDistance(0){}
        Warrior(int hp,int power):HP(hp),power(power),attackDistance(0){}
        virtual ~Warrior(){}

        int getHP() { return HP; }
        int getPower() { return power; }
        int getAttackDistance() { return attackDistance; }

        void setHP(int val);
        void setPower(int val);
        void setAttackDistance(int val);

        void beAttack(int harm);
        void attack(Warrior* obj);

        void beKill();  //not sure need or no need   [call by beAttack()]

    protected:
        int HP;
        int power;
        int attackDistance;

    private:
};

#endif // WARRIOR_H

#ifndef WARRIOR_H
#define WARRIOR_H

#include <Point.h>


class Warrior : public Point
{
    public:
        Warrior():speed(0),HP(0),power(0),attackDistance(0){}
        Warrior(int hp,int power):HP(hp),power(power),attackDistance(0){}
        virtual ~Warrior(){}

        int getSpeed() { return speed; }
        int getHP() { return HP; }
        int getPower() { return power; }
        int getAttackDistance() { return attackDistance; }

        void setSpeed(int val);
        void setHP(int val);
        void setPower(int val);
        void setAttackDistance(int val);

        void moveTo(Point* &target);
        void beAttack(int harm);
        void attack(Warrior* obj);

        void beKill();  //not sure need or no need   [call by beAttack()]

    protected:
        int speed;
        int HP;
        int power;
        int attackDistance;

    private:
};

#endif // WARRIOR_H

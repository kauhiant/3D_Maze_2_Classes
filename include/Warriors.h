#ifndef WARRIORS_H
#define WARRIORS_H
#include <vector>
#include "Point.h"
#include "Warrior.h"
class Warriors
{
    public:
        Warriors(Point Field);
        virtual ~Warriors();

        void add(Warrior* obj);
        int size();
        void output();
        void moveTo(Point* target);
        void attackTo(Warrior* target);
        Warrior* frontBy(Point target);
        void killDeadedWarrior();
    protected:

    private:
        std::vector<Warrior*> group;
        Point Field;
};

#endif // WARRIORS_H

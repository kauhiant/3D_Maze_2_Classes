#ifndef BATTLELINE_H
#define BATTLELINE_H

#include <vector>
#include "Warriors.h"
#include "Point.h"
class BattleLine
{
    public:
        BattleLine();
        BattleLine(int ACastleLevel,int BCastleLevel);
        virtual ~BattleLine();

        void nextStep();
        void AFieldPushWarrior(Warrior* obj);
        void BFieldPushWarrior(Warrior* obj);

    protected:

    private:
        Point AField;
        Point BField;
        Warriors A;
        Warriors B;
};

#endif // BATTLELINE_H

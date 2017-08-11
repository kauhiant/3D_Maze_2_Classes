#include <iostream>
#include <vector>
#include <cmath>

#include "Point.h"
#include "Warrior.h"
#include "Castle.h"
#include "Sword.h"
#include "Arrow.h"
#include "Warriors.h"
#include "BattleLine.h"

using namespace std;

int main()
{
    char cmd=' ';

//A��������3
//B��������4
    BattleLine Line(3,4);

/*�԰���
q:���}
a:�s�W�@���}�b�L��A
s:�s�W�@��C�L��A
z:�s�W�@���}�b�L��B
x:�s�W�@��C�L��B
*/
    while(cmd != 'q'){
        switch(cmd){
    case 'a':
        Line.AFieldPushWarrior(new Arrow());
        break;
    case 's':
        Line.AFieldPushWarrior(new Sword());
        break;
    case 'z':
        Line.BFieldPushWarrior(new Arrow());
        break;
    case 'x':
        Line.BFieldPushWarrior(new Sword());
        break;
    default:
        Line.nextStep();
        }

    cin>>cmd;
    }
    return 0;
}

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

//A城堡等級3
//B城堡等級4
    BattleLine Line(3,4);

/*戰鬥中
q:離開
a:新增一隻弓箭兵給A
s:新增一支劍兵給A
z:新增一隻弓箭兵給B
x:新增一支劍兵給B
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

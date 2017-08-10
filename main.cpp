#include <iostream>
#include <vector>
#include <cmath>

#include "Point.h"
#include "Warrior.h"
#include "Castle.h"
#include "Sword.h"
#include "Arrow.h"
#include "Warriors.h"
using namespace std;

int main()
{
    char cmd=' ';
//戰士團
    Warriors A;
    Warriors B;
//陣地
    Point AField;
    Point BField;
//設定陣地位置
    AField.setValue(0);
    BField.setValue(500);
//新增戰士團成員
    for(int i=0; i<5; ++i)
        A.add(new Sword(AField.getValue()));
    for(int i=0; i<5; ++i)
        B.add(new Arrow(BField.getValue()));
//顯示目前數據
    A.output();
    B.output();
//戰鬥中 q:離開 a:新增一隻弓箭兵給A b:新增一支劍兵給B
    while(cmd != 'q'){
    if(cmd == 'n'){
        //移動到對方的最前線
        A.moveTo(B.frontBy(BField));
        B.moveTo(A.frontBy(AField));
        //攻擊對方的最前線
        A.attackTo(B.frontBy(BField));
        B.attackTo(A.frontBy(AField));
        //把陣亡的戰士移除
        A.killDeadedWarrior();
        B.killDeadedWarrior();
        //顯示勝負
        if(A.size()==0)cout<<"A lose\n";
        if(B.size()==0)cout<<"B lose\n";

        A.output();
        B.output();
    }
    else if(cmd == 'a'){
        A.add(new Arrow(0));
    }
    else if(cmd == 'b'){
        B.add(new Sword(500));
    }
    cin>>cmd;
    }
    return 0;
}

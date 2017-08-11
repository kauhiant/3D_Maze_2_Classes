#include "BattleLine.h"
#include "Castle.h"
#include "Point.h"
#include <iostream>

BattleLine::BattleLine(int ACastleLevel,int BCastleLevel)
    :AField(0),BField(500),A(AField),B(BField)
{
  //  Warrior* tmp = new Castle(ACastleLevel);
    A.add(new Castle(ACastleLevel));
    B.add(new Castle(BCastleLevel));
}//Field

BattleLine::~BattleLine()
{
    //dtor
}

void BattleLine::nextStep(){
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
    if(A.size()==0)std::cout<<"A lose\n";
    if(B.size()==0)std::cout<<"B lose\n";

    A.output();
    B.output();
}

void BattleLine::AFieldPushWarrior(Warrior* obj){
    A.add(obj);
}
void BattleLine::BFieldPushWarrior(Warrior* obj){
    B.add(obj);
}

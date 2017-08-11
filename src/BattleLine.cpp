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
    //���ʨ��誺�̫e�u
    A.moveTo(B.frontBy(BField));
    B.moveTo(A.frontBy(AField));
    //������誺�̫e�u
    A.attackTo(B.frontBy(BField));
    B.attackTo(A.frontBy(AField));
    //��}�`���Ԥh����
    A.killDeadedWarrior();
    B.killDeadedWarrior();
    //��ܳӭt
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

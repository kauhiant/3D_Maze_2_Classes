#include <iostream>
#include <vector>
#include <cmath>

#include "Point.h"
#include "Warrior.h"
#include "Castle.h"
#include "Sword.h"
#include "Arrow.h"
using namespace std;

class Warriors{
private:
    vector<Warrior*> group;
    int initPosition;//no sure need or not need
public:
    Warriors(){}
    void add(Warrior* obj){
        group.push_back(obj);
    }
    int size(){
        return group.size();
    }
    void output(){
        cout<<endl;
        for(Warrior* &tmp : group)
            cout<<" value="<<tmp->getValue()<<"\tHP="<<tmp->getHP()<<'\n';
        cout<<endl;
    }

    void moveTo(Point* target){
        for(Warrior* &tmp : group)
            tmp->moveTo(target);
    }
    void attackTo(Warrior* target){
        for(Warrior* &tmp : group){
            tmp->attack(target);
        }
    }
    //��target�̻�
    Warrior* frontBy(Point target){
        int max = INT_MIN;
        Warrior* front;
        for(Warrior* tmp : group){
            if(abs(tmp->getValue()-target.getValue()) > max){
                front = tmp;
                max = abs(tmp->getValue()-target.getValue());
            }
        }
        return front;
    }

    //�⦺����������
    void killDeadedWarrior(){
        for(int i=0; i<group.size(); ++i){
            if(group[i]->getHP() == 0){
                delete group[i];
                group.erase(group.begin()+i);
                --i;
            }
        }
    }

};

int main()
{
    char cmd=' ';
//�Ԥh��
    Warriors A;
    Warriors B;
//�}�a
    Point AField;
    Point BField;
//�]�w�}�a��m
    AField.setValue(0);
    BField.setValue(500);
//�s�W�Ԥh�Φ���
    for(int i=0; i<5; ++i)
        A.add(new Sword(AField.getValue()));
    for(int i=0; i<5; ++i)
        B.add(new Arrow(BField.getValue()));
//��ܥثe�ƾ�
    A.output();
    B.output();
//�԰��� q:���} a:�s�W�@���}�b�L��A b:�s�W�@��C�L��B
    while(cmd != 'q'){
    if(cmd == 'n'){
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
        if(A.size()==0)cout<<"A lose\n";
        if(B.size()==0)cout<<"B lose\n";

        //���D
        //???��䤤�@���F�� �|�ۤv���ۤv???

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

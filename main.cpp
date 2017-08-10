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
    //離target最遠
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

    //把死掉的移除掉
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

        //問題
        //???當其中一方輸了後 會自己打自己???

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

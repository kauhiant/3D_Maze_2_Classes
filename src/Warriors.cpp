#include "Warriors.h"
#include <iostream>
#include <cmath>
Warriors::Warriors()
{
    //ctor
}

Warriors::~Warriors()
{
    //dtor
}
void Warriors::add(Warrior* obj){
        group.push_back(obj);
}
int Warriors::size(){
    return group.size();
}
void Warriors::output(){
    std::cout<<std::endl;
    for(Warrior* &tmp : group)
        std::cout<<" value="<<tmp->getValue()<<"\tHP="<<tmp->getHP()<<'\n';
    std::cout<<std::endl;
}

void Warriors::moveTo(Point* target){
    if(target == nullptr)
        return;

    for(Warrior* &tmp : group)
        tmp->moveTo(target);
}
void Warriors::attackTo(Warrior* target){
    if(target == nullptr)
        return;

    for(Warrior* &tmp : group){
        tmp->attack(target);
    }
}
//離target最遠
Warrior* Warriors::frontBy(Point target){
    int max = INT_MIN;
    Warrior* front = nullptr;
    for(Warrior* tmp : group){
        if(std::abs(tmp->getValue()-target.getValue()) > max){
            front = tmp;
            max = std::abs(tmp->getValue()-target.getValue());
        }
    }
    return front;
}

//把死掉的移除掉
void Warriors::killDeadedWarrior(){
    for(int i=0; i<group.size(); ++i){
        if(group[i]->getHP() == 0){
            delete group[i];
            group.erase(group.begin()+i);
            --i;
        }
    }
}

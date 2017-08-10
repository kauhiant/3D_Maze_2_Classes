#include <iostream>
#include "Point.h"
#include "Warrior.h"
#include "Castle.h"
#include "Sword.h"
#include "Arrow.h"
using namespace std;

void output( Warrior* a, Warrior* b){
    cout<<"a:value="<<a->getValue()<<" HP="<<a->getHP()<<" attackDistance="<<a->getAttackDistance()<<'\n'
    <<"b:value="<<b->getValue()<<" HP="<<b->getHP()<<" attackDistance="<<b->getAttackDistance()<<'\n';
}

int main()
{
    Warrior *a = new Castle(0,1);
    Warrior *b = new Arrow(100);

    while(a->getHP() > 0 && b->getHP() > 0){
        output(a,b);
        if(a->distance(b) > a->getAttackDistance())
            a->moveTo(b);
        if(b->distance(a) > b->getAttackDistance())
            b->moveTo(a);
        a->attack(b);
        b->attack(a);
        cin.get();
    }
    output(a,b);
    return 0;
}

#ifndef CASTLE_H
#define CASTLE_H

#include <Warrior.h>


class Castle : public Warrior
{
    public:
        Castle(int position,int level);
        virtual ~Castle();

    protected:

    private:
        const int level;
};

#endif // CASTLE_H

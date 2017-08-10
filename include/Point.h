#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point():value(0){}

        int getValue() { return value; }

        void setValue(int val);

        int distance(Point* other);

    protected:
        int value;


    private:
};

#endif // POINT_H

#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point(int val = 0):value(val){}

        int getValue() { return value; }

        void setValue(int val);

        int distance(Point* other);

    protected:
        int value;


    private:
};

#endif // POINT_H

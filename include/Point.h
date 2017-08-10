#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point():value(0),speed(0){}

        int getValue() { return value; }
        int getSpeed() { return speed; }

        void setValue(int val);
        void setSpeed(int val);

        int distance(Point* other);
        void moveTo(const Point* target);

    protected:
        int value;
        int speed;

    private:
};

#endif // POINT_H

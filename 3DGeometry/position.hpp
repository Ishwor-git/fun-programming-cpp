#ifndef POSITION_HPP
#define POSITION_HPP
#include <iostream>
#include <cmath>
class Position
{
protected:
public:
    float x, y, z;
    Position(void);
    Position(float, float, float);
    friend std::ostream &operator<<(std::ostream &, Position &);
    friend float distance(Position &, Position &);
    friend bool isColinear(Position &, Position &, Position &);
};
Position::Position() : x(0), y(0), z(0) {}

Position::Position(float x, float y, float z) : x(x), y(y), z(z) {}

std::ostream &operator<<(std::ostream &out, Position &p)
{
    out << "( " << p.x << ", " << p.y << ", " << p.z << " )";
    return out;
}

float distance(Position &p1, Position &p2)
{
    float dis;
    dis = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
    return dis;
}

bool isColinear(Position &p1, Position &p2, Position &p3)
{
    if (((p1.x == 0 && p1.y == 0) || (p1.y == 0 && p1.z == 0) || (p1.z == 0 && p1.x == 0)) &&
        ((p2.x == 0 && p2.y == 0) || (p2.y == 0 && p2.z == 0) || (p2.z == 0 && p2.x == 0)) &&
        ((p3.x == 0 && p3.y == 0) || (p3.y == 0 && p3.z == 0) || (p3.z == 0 && p3.x == 0)))
    {
        return true;
    }

    float r1 = (p2.x - p1.x) / (p3.x - p2.x);
    float r2 = (p2.y - p1.y) / (p3.y - p2.y);
    float r3 = (p2.z - p1.z) / (p3.z - p2.z);
    if (r1 == r2 && r2 == r3)
    {
        return true;
    }
    return false;
}
#endif // POSITION_HPP
#ifndef POSITION_HPP
#define POSITION_HPP
#include <iostream>
#include <cmath>
using namespace std;
class Position
{
protected:
public:
    float xAxis, yAxis, zAxis;
    Position(void);
    Position(float, float, float);
    friend ostream &operator<<(ostream &, Position &);
    friend float distance(Position &, Position &);
};
Position::Position() : xAxis(0), yAxis(0), zAxis(0) {}

Position::Position(float x, float y, float z) : xAxis(x), yAxis(y), zAxis(z) {}

ostream &operator<<(ostream &out, Position &p)
{
    out << "( " << p.xAxis << ", " << p.yAxis << ", " << p.zAxis << " )";
    return out;
}

float distance(Position &p1, Position &p2)
{
    float dis;
    dis = sqrt(pow(p2.xAxis - p1.xAxis, 2) + pow(p2.yAxis - p1.yAxis, 2) + pow(p2.zAxis - p1.zAxis, 2));
    return dis;
}
#endif // POSITION_HPP
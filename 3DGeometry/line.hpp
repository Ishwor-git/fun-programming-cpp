#ifndef LINE_HPP
#define LINE_HPP
#include "position.hpp"
#include "ratio.hpp"
#include <cmath>

class Line : public Position
{
private:
    Position initial, final;

public:
    Line(Position, Position);
    Ratio3 dRatio(void);
    Ratio3 dCosine(void);
    float length(void);
    friend float LAngle(Line &, Line &);
    friend Position ratioFormula(Line &, Ratio2 &);
};

Line::Line(Position p1, Position p2) : initial(p1), final(p2) {}

Ratio3 Line ::dRatio()
{
    Ratio3 dr;
    float a = final.x - initial.x;
    float b = final.y - initial.y;
    float c = final.z - initial.z;
    dr = {a, b, c};
    return dr;
}
Ratio3 Line ::dCosine()
{
    Ratio3 dc, dr;
    dr = dRatio();
    float divisor = sqrt(pow(dr.getA(), 2) + pow(dr.getB(), 2) + pow(dr.getC(), 2));
    dc = {dr.getA() / divisor, dr.getB() / divisor, dr.getC() / divisor};
    return dc;
}

float Line ::length() { return distance(initial, final); }

float LAngle(Line &l1, Line &l2)
{
    float deg, divident, divisor;
    Ratio3 dc1, dc2;
    dc1 = l1.dCosine();
    dc2 = l2.dCosine();
    divident = dc1.getA() * dc2.getA() + dc1.getB() * dc2.getB() + dc1.getC() * dc2.getC();
    divisor = sqrt(pow(dc1.getA(), 2) + pow(dc1.getB(), 2) + pow(dc1.getC(), 2)) * sqrt(pow(dc2.getA(), 2) + pow(dc2.getB(), 2) + pow(dc2.getC(), 2));
    deg = acos(divident / divisor);
    return deg;
}

Position ratioFormula(Line &l, Ratio2 &r)
{
    Position p;
    float rSum = r.getM1() + r.getM2();
    p.x = ((r.getM1() * l.final.x) + (r.getM2() * l.initial.x)) / rSum;
    p.y = ((r.getM1() * l.final.y) + (r.getM2() * l.initial.y)) / rSum;
    p.z = ((r.getM1() * l.final.z) + (r.getM2() * l.initial.z)) / rSum;
    return p;
}

#endif // LINE_HPP
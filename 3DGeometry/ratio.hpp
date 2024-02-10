#ifndef RATIO_HPP
#define RATIO_HPP
#include <iostream>

class Ratio2
{
private:
    float m1, m2;

public:
    Ratio2(void);
    Ratio2(float, float);
    // ostream &operator<<(ostream &);
    friend std::ostream &operator<<(std::ostream &, const Ratio2 &);
    float getM1() const { return m1; }
    float getM2() const { return m2; }
};
class Ratio3
{
private:
    float a, b, c;

public:
    float getA() const { return a; }
    float getB() const { return b; }
    float getC() const { return c; }

    Ratio3(void);
    Ratio3(float, float, float);
    friend std::ostream &operator<<(std::ostream &, const Ratio3 &);
};
Ratio2::Ratio2() : m1(1), m2(1) {}

Ratio2::Ratio2(float r1, float r2) : m1(r1), m2(r2) {}

Ratio3::Ratio3() : a(1), b(1), c(1) {}

Ratio3::Ratio3(float r1, float r2, float r3) : a(r1), b(r2), c(r3) {}

// ostream &Ratio2::operator<<(ostream &out) const
// {
//     out << getM1() << " / " << getM2();
//     // out << r.m1 << " / " << r.m2;
//     return out;
// }
std::ostream &operator<<(std::ostream &out, const Ratio2 &r)
{
    out << r.getM1() << " / " << r.getM2();
    // out << r.m1 << " / " << r.m2;
    return out;
}

std::ostream &operator<<(std::ostream &out, const Ratio3 &r)
{
    out << "( " << r.getA() << ", " << r.getB() << ", " << r.getC() << " )";
    // out << "( " << r.a << ", " << r.b << ", " << r.c << " )";

    return out;
}
#endif // RATIO_HPP
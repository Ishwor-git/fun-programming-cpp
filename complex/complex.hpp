#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
    float real, imag;

public:
    Complex(void);
    Complex(float, float);
    friend Complex operator+(Complex &, Complex &);
    friend Complex operator-(Complex &, Complex &);
    friend Complex operator*(Complex &, Complex &);
    friend Complex operator/(Complex &, Complex &);
    friend float magnitude(Complex &);
    friend float arg(Complex &);
    friend ostream &operator<<(ostream &, const Complex &);
};

Complex ::Complex() : real(0), imag(0) {}

Complex::Complex(float r, float i) : real(r), imag(i) {}

Complex operator+(Complex &c1, Complex &c2)
{
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}
Complex operator-(Complex &c1, Complex &c2)
{
    Complex temp;
    temp.real = c1.real - c2.real;
    temp.imag = c1.imag - c2.imag;
    return temp;
}
Complex operator*(Complex &c1, Complex &c2)
{
    Complex temp;
    temp.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    temp.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    return temp;
}

Complex operator/(Complex &c1, Complex &c2)
{
    Complex temp1, temp2;
    temp1 = c1 * c2;
    float divisor = (c2.real * c2.real) + (c2.imag * c2.imag);
    temp2.real = temp1.real / divisor;
    temp2.imag = temp1.imag / divisor;
    return temp2;
}

float magnitude(Complex &c1)
{
    float result = sqrt(c1.real * c1.real + c1.imag * c1.imag);
    return result;
}

float arg(Complex &c1)
{
    float result = atan(c1.imag / c1.real);
    return result;
}

ostream &operator<<(ostream &out, const Complex &c)
{
    out << "(" << c.real << ", " << c.imag << "i)";
    return out;
}
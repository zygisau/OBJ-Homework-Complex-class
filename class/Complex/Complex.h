//
// Created by zygisau on 10/04/2019.
//

#ifndef DUOMENU_APDOROJIMAS_COMPLEX_H
#define DUOMENU_APDOROJIMAS_COMPLEX_H

#include <iostream>
using std::cout; using std::cin; using std::ostream; using std::istream; using std::endl;

class Complex {
    double re, im;  // realioji ir menamoji dalis
public:
    Complex(double r, double i) : re{r}, im{i} {}

    double real() const { return re; }
    double imag() const { return im; }
    double real(double sk) { return re = sk; }
    double imag(double sk) { return im = sk; }
    istream& inputReal(std::istream& stream) {return stream >> re; }
    istream& inputImag(std::istream& stream) {return stream >> im; }

    Complex& operator+=(const Complex c) { re += c.re, im += c.im; return *this;  }
    Complex& operator-=(const Complex c) { re -= c.re, im -= c.im;  return *this;  }
    Complex& operator*=(const Complex c);
};

Complex operator+(Complex& a, const Complex& b);
Complex operator-(Complex& a, const Complex& b);
Complex operator-(const Complex& a);
Complex operator*(Complex& a, const Complex& b);
bool operator==(const Complex a, const Complex b);
bool operator!=(const Complex& a, const Complex& b);
ostream& operator<<(std::ostream& out, const Complex &a);
istream& operator>>(std::istream& in, Complex &a);

#endif //DUOMENU_APDOROJIMAS_COMPLEX_H

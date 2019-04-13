//
// Created by zygisau on 10/04/2019.
//

#include "Complex.h"

Complex& Complex::operator*=(const Complex c) {
    double reOld = re, imOld = im;
    re = reOld * c.real() - imOld * c.imag(); // (a, b) * (c, d) = (ac - bd,ad + bc)
    im = reOld * c.imag() + imOld * c.real();
    return *this;
} // Realizuokite patys!

Complex operator+(Complex a, const Complex& b) { return a += b; }

Complex operator-(Complex a, const Complex& b) { return a -= b; }

Complex operator-(const Complex& a)  { // vienanaris minus
    return Complex{ -a.real(), -a.imag() }; // neiginys
}

Complex operator*(Complex& a, const Complex& b) { return a *= b; }

bool operator==(const Complex a, const Complex b) {
    return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(const Complex a, const Complex b) { return !(a == b); }

ostream& operator<<(ostream& out, const Complex &a) {
    out << a.real() << ( (a.imag() > 0) ? " + " : " " ) << a.imag() << "i\n";
    return out;
}

std::istream& operator>>(std::istream& in, Complex &a) {
    double sk1, sk2;
    in >> sk1 >> sk2;
    a.real(sk1);
    a.imag(sk2);
    return in;
}

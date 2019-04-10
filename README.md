# Operator overloading

## Complex klasė

```c++
class Complex {
    double re, im;  // realioji ir menamoji dalis
public:
    Complex(double r, double i) : re{r}, im{i} {}

    double real() const { return re; }
    double imag() const { return im; }
    double real(double sk) { return re = sk; }
    double imag(double sk) { return im = sk; }
    istream& inputReal(std::istream& stream) {return stream >> re; } // input interface
    istream& inputImag(std::istream& stream) {return stream >> im; } //

    Complex& operator+=(Complex c) { re += c.re, im += c.im; return *this;  }
    Complex& operator-=(Complex c) { re -= c.re, im -= c.im;  return *this;  }
    Complex& operator*=(Complex c);
};
```



## 1 užduotis

Atspausdintas kompleksinis skaičius turi dinamiškai turėti + arba - išraiškoje prieš menamąją dalį.

```c++
ostream& operator<<(ostream& out, const Complex &a) {
    out << a.real() << ( (a.imag() > 0) ? " + " : " " ) << a.imag() << "i\n";
    return out;
}
```

```c++
Complex a{1, 1}, b{-2, -2};
cout << (a *= b) << endl;
```

```bash
Atsakymas: 0 -4i
```



## 2 užduotis

**Overload operator>>**

```c++
...
istream& inputReal(std::istream& stream) {return stream >> re; } // input interface
istream& inputImag(std::istream& stream) {return stream >> im; } //
...
```

```c++
std::istream& operator>>(std::istream& in, Complex &a) {
    double sk1, sk2;
    in >> sk1 >> sk2;
    a.real(sk1);
    a.imag(sk2);
    return in;
}
```



## 3 užduotis

```c++
Complex& operator+=(const Complex c) VS
Complex operator+=(const Complex c)
```

**Kompiliatorius leidžia abiem realizacijom.**

![rule](.\photos\rule.png)

> An ***lvalue*** (*locator value*) represents an **object that occupies some identifiable location** in memory (i.e. has an address).
>
> ***rvalue*** is an expression that ***does not* represent an object occupying some identifiable location in memory**.

#### Kodėl stream ne per reference grąžinti negalima?

![iostream reference](C:\Users\zygisau\Documents\Uni\OBJ-Homework-Complex-class\photos\iostream reference.png)



## 4 užduotis

**Operator*=**

```c++
Complex& Complex::operator*=(const Complex c) {
    double reOld = re, imOld = im;
    re = reOld * c.real() - imOld * c.imag(); // (a, b) * (c, d) = (ac - bd,ad + bc)
    im = reOld * c.imag() + imOld * c.real();
    return *this;
}
```



## 5 užduotis

**Operator-**

```c++
Complex operator-(const Complex& a)  { // vienanaris minus
    return Complex{ -a.real(), -a.imag() }; // neiginys
}
```

**std::complex realizacija**

```c++
  ///  Return complex negation of @a x.
  template<typename _Tp>
    inline complex<_Tp>
    operator-(const complex<_Tp>& __x)
    {  return complex<_Tp>(-__x.real(), -__x.imag()); }
```



<hr>

### Šaltiniai į paveikslėlius

- THE RULE <https://stackoverflow.com/questions/2337213/return-value-of-operator-overloading-in-c>

- lvalue and rvalue <https://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c/>

- Return by reference iostream <https://stackoverflow.com/questions/6010864/why-copying-stringstream-is-not-allowed>
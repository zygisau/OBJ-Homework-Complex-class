#include "class/Complex/Complex.h"

int main() {
    Complex a{1, 1}, b{-2, -2};
    cout << "a + b    " << a + b;
    cout << "a - b    " << a - b;
    cout << "a * b    " << a * b;
    cout << "a += b    " << (a += b);
    cout << "a -= b    " << (a -= b);
    cout << "a *= b    " << (a *= b);
    cout << "a == b    " << (a == b) << endl;
    cout << "a != b    " << (a != b) << endl;
    cin >> a;
    cout << a << endl;
    return 0;
}
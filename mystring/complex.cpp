#include <iostream>
using namespace std;

class Complex {
    double re, im;

public:
    Complex() {
        re = 0;
        im = 0;
    }

    Complex(double real, double imagine) {
        re = real;
        im = imagine;
    }

    void print() {
        if (im >= 0) {
            cout << re << "+" << im << "i" << endl;
        }
        else {
            cout << re << "-" << im << "i" << endl;
        }
    }

    Complex sopr() {
        return Complex(re, -im);
    }

    Complex operator*(Complex& other) {
        double real = (re * other.re - im * other.im);
        double imagine = (re * other.im + im * other.re);
        return Complex(real, imagine);
    }

    Complex operator/(double num) {
        double real = re / num;
        double imagine = im / num;
        return Complex(real, imagine);
    }

    Complex operator/(Complex& other) {
        double d = (other * other.sopr()).re;
        return (*this * other.sopr())/d;
    }

    void PutValue(double real, double imagine) {
        re = real;
        im = imagine;
    }
};

int main() {
    Complex a, c;
    a.print();
    Complex b(3.0, 4.0);
    b.print();
    a.PutValue(1, 2);
    a.print();
    (c=a/b).print();
    (c*b).print();
}



#include "complex.h"

#include <cmath>

Complex::Complex(const double re, const double im) {
    this->re = re;
    this->im = im;
}
Complex::Complex(const Complex& c) {
    re = c.re;
    im = c.im;
}
Complex& Complex::operator=(const Complex& c) {
    re = c.re;
    im = c.im;

    return *this;
}

Complex Complex::polar(const double leng, const double arg) {
    re = leng * cos(arg);
    im = leng * sin(arg);

    return *this;
}

double Complex::real() const {
    return re;
}
double Complex::imag() const {
    return im;
}
double Complex::norm() const {
    return re * re + im * im;
}
double Complex::abs() const {
    return sqrt(norm());
}
double Complex::arg() const {
    return atan2(im, re);
}

// Pre-increment operator
Complex Complex::operator++() {
    re++;
    im++;

    return *this;
}
// Post-increment operator
Complex Complex::operator++(int) {
    Complex temp = *this;

    re++;
    im++;

    return temp;
}
Complex Complex::operator--() {
    re--;
    im--;

    return *this;
}
Complex Complex::operator--(int) {
    Complex temp = *this;

    re--;
    im--;

    return *this;
}

Complex::~Complex() {}

// Friend Function
Complex polar(const double leng, const double arg) {
    Complex temp;

    temp.re = leng * cos(arg);
    temp.im = leng * sin(arg);

    return temp;
}
double norm(const Complex& x) {
    return x.norm();
}
double abs(const Complex& x) {
    return x.abs();
}
double arg(const Complex& x) {
    return x.arg();
}

Complex operator+(const Complex& x, const Complex& y) {
    Complex temp;

    temp.re = x.re + y.re;
    temp.im = x.im + y.im;

    return temp;
}
Complex operator-(const Complex& x, const Complex& y) {
    Complex temp;

    temp.re = x.re - y.re;
    temp.im = x.im - y.im;

    return temp;
}
Complex operator*(const Complex& x, const Complex& y) {
    Complex temp;

    temp.re = x.re * y.re - x.im * y.im;
    temp.im = x.im * y.re + x.re * y.im;

    return temp;
}
Complex operator/(const Complex& x, const Complex& y) {
    Complex temp;
    double deno = y.re * y.re + y.im * y.im;

    temp.re = (x.re * y.re + x.im * y.im) / deno;
    temp.im = (x.im * y.re - x.re * y.im) / deno;

    return temp;
}
Complex operator+=(Complex& x, const Complex& y) {
    x = x + y;

    return x;
}
Complex operator-=(Complex& x, const Complex& y) {
    x = x - y;

    return x;
}
Complex operator*=(Complex& x, const Complex& y) {
    x = x * y;

    return x;
}
Complex operator/=(Complex& x, const Complex& y) {
    x = x / y;

    return x;
}
bool operator==(const Complex& x, const Complex& y) {
    return x.re == y.re && x.im == y.im;
}
bool operator!=(const Complex& x, const Complex& y) {
    return !(x.re == y.re && x.im == y.im);
}
ostream& operator<<(ostream& o, const Complex& x) {
    o << "(" << x.re << ',' << x.im << ')';

    return o;
}

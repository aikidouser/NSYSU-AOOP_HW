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
}

double Complex::real() {
    return re;
}
double Complex::imag() {
    return im;
}
double Complex::norm() {
}
double Complex::abs() {
}
double Complex::arg() {
}

Complex Complex::operator++() {
}
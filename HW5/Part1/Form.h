#ifndef __FORM_H__
#define __FORM_H__

#include <iomanip>
#include <iostream>

class Form {
   public:
    Form(const unsigned int& p) : prec(p), ff(std::cout.flags()) {}
    friend std::ostream& operator<<(std::ostream& out, const Form& f);

    inline Form& scientific() {
        // format = 1;
        ff |= std::cout.scientific;

        return *this;
    }

    inline Form& fixed() {
        ff |= std::cout.fixed;

        return *this;
    }

    inline Form& precision(const unsigned int& p) {
        prec = p;

        return *this;
    }

    inline Form& operator()(const double& d) {
        val = d;

        return *this;
    }

   private:
    int prec;
    double val;
    // int format;  // 0 -> general, 1 -> scientific, 2 -> fixed
    std::ios_base::fmtflags ff;
};
#endif
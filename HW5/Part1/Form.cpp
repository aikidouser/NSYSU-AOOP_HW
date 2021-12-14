#include "Form.h"

using namespace std;

ostream& operator<<(std::ostream& out, const Form& f) {
    out.flags(f.ff);
    out << setprecision(f.prec) << f.val;
    out.unsetf(f.ff);
    out << setprecision(-1);

    return out;
}
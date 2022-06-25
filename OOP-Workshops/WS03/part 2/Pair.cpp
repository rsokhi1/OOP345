#include <iostream>
#include "Pair.h"
using namespace std;
namespace sdds {
    std::ostream& Pair::display( ostream& ostr) {
        ostr.width(20);
        ostr.setf(ios::right);
        ostr << getKey();
        ostr.unsetf(ios::right);
        ostr.setf(ios::left);
        ostr << ": " << getValue();
        return ostr;
    }
    bool operator==(const Pair& lhs,const Pair& rhs) {
        return lhs.getKeyConst() == rhs.getKeyConst();
    }

    std::ostream& operator<<(std::ostream& ostr, Pair& P) {
        return P.display(ostr);
    }
}
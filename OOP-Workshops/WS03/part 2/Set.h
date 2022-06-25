#ifndef SDDS_SET_H_
#define SDDS_SET_H_
#include "Collection.h"

namespace sdds {
    template<typename T>
    class Set : public Collection<T,100>{
        double myAbs(const double& D) {
            return D < 0 ? -D : D;
        }
    public:
        bool add(const T& item) {
            bool flag = false;
            for (unsigned int i = 0; i < this->size(); i++) {
                if (item == (*this)[i]) {
                    flag = true;
                }
            }
            return (flag == true) ? false : Collection<T, 100>::add(item);
        }

    };


    template<>
    bool Set<double>::add(const double& item) {
        bool flag = false;
        for (unsigned int i = 0; i < this->size(); i++) {
            if (myAbs((*this)[i] - item) <= 0.01) {
                flag = true;
            }
        }
        return (flag == true) ? false : Collection<double, 100>::add(item);
    }
}

#endif // !SDDS_SET_H_


#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
    template<typename T>
    class GeneratingList {

        std::vector<T> list;
    public:

        GeneratingList() {}
        GeneratingList(const char* f) {
            std::ifstream file(f);
            if (!file)
                throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

            while (file) {
                T t;
                if (t.load(file))
                    list.push_back(T(t));
            }
        }

        size_t size() const { return list.size(); }
        const T& operator[](size_t i) const { return list[i]; }

        //TODO: Implement the Luhn Algorithm to check the
        //      valadity of SIN No's
        bool isValidSIN(const std::string& sin) {
            int nDigits = sin.length();
            int sum = std::stoi(sin.substr(nDigits - 1, 1));
            int parity = (nDigits - 2) % 2;
            for (int i = 0; i <= nDigits - 2; i++) {
                int digit = std::stoi(sin.substr(i, 1));
                if ((i % 2) == parity)
                    digit = digit * 2;
                if (digit > 9)
                    digit -= 9;
                sum += digit;
            }
            return (sum % 10) == 0;
        }

        
        void operator+=(std::unique_ptr<T> record) {
            list.push_back(*record);
        }

        
        void operator+=(T* record) {
            list.push_back(*record);
        }


        void print(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.print(os);
        }
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
        rd.print(os);
        return os;
    }
}
#endif 
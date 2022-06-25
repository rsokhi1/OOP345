#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include "Pair.h"
namespace sdds {
    template<typename T, unsigned int CAPACITY>
    class Collection {
        T m_item[CAPACITY]{};
        unsigned int m_size{};
        T dummy{};
    public:
        Collection() {}
        unsigned int size() const {
            return m_size;
        }

        std::ostream& display(std::ostream& ostr = std::cout) {
            ostr << "----------------------" << std::endl;
            ostr << "| Collection Content |" << std::endl;
            ostr << "----------------------" << std::endl;
            for (unsigned int i = 0; i < m_size; i++) {
                ostr << m_item[i] << std::endl;
            }
            ostr << "----------------------" << std::endl;
            return ostr;
        }

        bool add(const T& item) {
            bool flag = false;
            if (m_size < CAPACITY) {
                m_item[m_size] = item;
                m_size++;
                flag = true;
            }
            return flag;
        }

        T& operator[](unsigned int index) {
            return index >= 0 && index < m_size ? m_item[index] : dummy;
        }
    };
    

    template<>
    Collection<Pair, 100>::Collection() {
        Pair a("No Key", "No Value");
        dummy = a;
    }
}

#endif // !SDDS_COLLECTION_H_
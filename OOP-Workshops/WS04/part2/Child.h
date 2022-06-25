/*Workshop #4 Part #2
        Name        : Rajbeer Sokhi
        StudentId   : 124969205
        Email       : rsokhi1@myseneca.ca
        Section     : NBB
        Date        : 15th February 2022
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CHILD_H_ 
#define SDDS_CHILD_H_
#include "Toy.h"
namespace sdds{
    class Child{
        std::string m_name{};
        int m_age{};
        const Toy** m_toy{};
        size_t m_size{};
        void setEmpty();
    public: 
        Child(std::string name, int age, const Toy* toys[], size_t count);
        size_t size() const;
        friend std::ostream& operator<<(std::ostream& ostr,const Child& c); 
        Child(const Child& C);
        Child& operator=(const Child& C);
        Child(Child&& C);
        Child& operator=(Child&& C);
        ~Child();
    };
}

#endif // !SDDS_CHILD_H_
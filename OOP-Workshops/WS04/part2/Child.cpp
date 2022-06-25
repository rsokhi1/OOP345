/*Workshop #4 Part #2
        Name        : Rajbeer Sokhi
        StudentId   : 124969205
        Email       : rsokhi1@myseneca.ca
        Section     : NBB
        Date        : 15th February 2022
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "Child.h"
namespace sdds
{
    void Child::setEmpty()
    {
        m_name = "";
        m_age = 0;
        for (size_t i = 0; i < m_size; i++)
            delete m_toy[i];
        delete[] m_toy;
        m_toy = nullptr;
        m_size = 0;
    }

    Child::Child(std::string name, int age, const Toy* toys[], size_t count)
    {
        if (toys != nullptr) {
            setEmpty();
            m_name = name;
            m_age = age;
            m_size = count;
            m_toy = new const Toy * [m_size];
            for (size_t i = 0; i < m_size; i++) {
                m_toy[i] = new Toy(*toys[i]);
            }
        }
        else {
            setEmpty();
        }
    }

    size_t Child::size() const
    {
        return m_size;
    }

    Child::Child(const Child& C)
    {
        operator=(C);
    }

    Child& Child::operator=(const Child& C)
    {
        if (this != &C) {
            setEmpty();
            m_name = C.m_name;
            m_age = C.m_age;
            m_size = C.m_size;
            m_toy = new const Toy * [m_size];
            for (size_t i = 0; i < m_size; i++) {
                m_toy[i] = new Toy(*C.m_toy[i]);
            }
        }
        return *this;
    }

    Child::Child(Child&& C)
    {
        operator=(std::move(C));
    }

    Child& Child::operator=(Child&& C)
    {
        if (this != &C) {
            setEmpty();
            //assuming C's property
            m_name = C.m_name;
            m_age = C.m_age;
            m_toy = C.m_toy;
            m_size = C.m_size;
            // wiping C's property
            C.m_toy = nullptr;
            C.m_name = "";
            C.m_age = 0;
            C.m_size = 0;
        }
        return *this;
    }

    Child::~Child()
    {
        setEmpty();
    }

    std::ostream& operator<<(std::ostream& ostr, const Child& c)
    {
        static int counter = 0;
        counter++;
        ostr << "--------------------------" << std::endl;
        ostr << "Child " << counter << ": " << c.m_name << " " << c.m_age << " years old:" << std::endl;
        ostr << "--------------------------" << std::endl;
        if (c.m_size != 0) {
            for (size_t i = 0; i < c.m_size; i++) {
                ostr << *c.m_toy[i];
            }
        }
        else {
            ostr << "This child has no toys!" << std::endl;
        }
        ostr << "--------------------------" << std::endl;
        return ostr;

    }
}
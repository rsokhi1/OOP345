/*Workshop #4 Part #2
        Name        : Rajbeer Sokhi
        StudentId   : 124969205
        Email       : rsokhi1@myseneca.ca
        Section     : NBB
        Date        : 15th February 2022
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include<iostream>
#include "ConfirmOrder.h"
namespace sdds
{
    ConfirmOrder::ConfirmOrder() {
        m_toy = nullptr;
        m_size = 0;
    }
    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) 
    {
        bool flag = false;
        for (size_t i = 0; i < m_size && !flag; i++) {
            if (&toy == m_toy[i]) {
                flag = true;
            }
        }
        if (!flag) {
            const Toy** temp = new const Toy * [m_size + 1];
            for (size_t i = 0; i < m_size; i++) {
                temp[i] = m_toy[i];
            }
            temp[m_size] = &toy;
            m_size++;
            delete [] m_toy;
            m_toy = temp;
            temp = nullptr;
        }
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
        for (size_t i = 0; i < m_size; i++) {
            if (&toy == m_toy[i]) {
                m_toy[i] = nullptr;
                m_size--;
            }
        }
        return *this;
    }

    ConfirmOrder::ConfirmOrder(const ConfirmOrder& C) {
        operator=(C);
    }

    ConfirmOrder::ConfirmOrder(ConfirmOrder&& C) {
        operator=(std::move(C));
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& C) {
        if (this != &C) {
            delete[] m_toy;
            m_size = C.m_size;
            m_toy = new const Toy * [m_size];
            for (size_t i = 0; i < m_size; i++) {
                m_toy[i] = C.m_toy[i];
            }
        }
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& C) {
        if (this != &C) {
            delete[] m_toy;
            m_toy = nullptr;
            m_size = C.m_size;
            m_toy = C.m_toy;
            C.m_toy = nullptr;
            C.m_size = 0;
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& C) {
        ostr << "--------------------------" << std::endl;
        ostr << "Confirmations to Send" << std::endl;
        ostr << "--------------------------" << std::endl;

        if (C.m_size == 0) {
            ostr << "There are no confirmations to send!" << std::endl;
            
        }
        else {
            for (size_t i = 0; i < C.m_size; i++) {
                if (C.m_toy[i] != nullptr) {
                    ostr << *C.m_toy[i];
                }
            }
        }
        ostr << "--------------------------" << std::endl;
        return ostr;
    }

    ConfirmOrder::~ConfirmOrder() {
        delete[] m_toy;
        m_toy = nullptr;
    }

}
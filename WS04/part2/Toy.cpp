/*Workshop #4 Part #2
        Name        : Rajbeer Sokhi
        StudentId   : 124969205
        Email       : rsokhi1@myseneca.ca
        Section     : NBB
        Date        : 15th February 2022
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Toy.h"
namespace sdds
{

    /*Toy& Toy::operator=(const Toy& T) {
        if (this != &T) {
            m_orderId = T.m_orderId;
            m_name = T.m_name;
            m_numItems = T.m_numItems;
            m_price = T.m_price;
            m_tax = T.m_tax;
        }
        return *this;
    }*/

    void Toy::update(int numItems) 
    {   
        m_numItems = numItems;        
    }
    
    Toy::Toy(const std::string& str) 
    {
        std::string local_str = str;

        local_str.erase(0, local_str.find_first_not_of(' '));
        size_t index = local_str.find(':');
        std::string tempStr = local_str.substr(0, index);
        tempStr.erase(tempStr.find_last_not_of(' ') + 1);
        m_orderId = stoi(tempStr);

        local_str.erase(0, index + 1);
        local_str.erase(0, local_str.find_first_not_of(' '));
        index = local_str.find(':');
        tempStr = local_str.substr(0, index);
        tempStr.erase(tempStr.find_last_not_of(' ') + 1);
        m_name = tempStr;

        local_str.erase(0, index + 1);
        local_str.erase(0, local_str.find_first_not_of(' '));
        index = local_str.find(':');
        tempStr = local_str.substr(0, index);
        tempStr.erase(tempStr.find_last_not_of(' ') + 1);
        m_numItems = stoi(tempStr);

        local_str.erase(0, index + 1);
        local_str.erase(0, local_str.find_first_not_of(' '));
        index = local_str.find(':');
        tempStr = local_str.substr(0, index);
        tempStr.erase(tempStr.find_last_not_of(' ') + 1);
        m_price = stod(tempStr);
    }
    
    std::ostream& operator<<(std::ostream& ostr, const Toy& t) 
    {
        double tax = t.m_price * t.m_numItems * 0.13;
        ostr<<"Toy";
        ostr.width(8);
        ostr<<t.m_orderId<<":";
        ostr.width(18);
        ostr.setf(std::ios::right);
        ostr<<t.m_name;
        ostr.width(3);
        ostr<<t.m_numItems<<" items";
        ostr.width(8);
        ostr<<t.m_price<<"/item  subtotal:";
        ostr.width(7);
        ostr<<t.m_price * t.m_numItems<<" tax:";   
        ostr.width(6);
        ostr<<std::fixed<<std::setprecision(2)<<tax<<" total:";
        ostr.width(7);
        ostr<<(t.m_price * t.m_numItems) + tax<<std::endl;
        ostr.unsetf(std::ios::right);
        return ostr;
    }


    
}
#include <iostream>
#include <iomanip>
#include <string>
#include "Toy.h"
using namespace std;
namespace sdds
{
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
        ostr.setf(ios::right);
        ostr<<t.m_name;
        ostr.width(3);
        ostr<<t.m_numItems<<" items";
        ostr.width(8);
        ostr<<t.m_price<<"/item subtotal:";
        ostr.width(7);
        ostr<<t.m_price * t.m_numItems<<" tax:";   
        ostr.width(6);
        ostr<<std::fixed<<setprecision(2)<<tax<<" total:";
        ostr.width(7);
        ostr<<(t.m_price * t.m_numItems) + tax<<endl;
        ostr.unsetf(ios::right);
        return ostr;
    }
}
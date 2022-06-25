/*Workshop #1 Part #1
        Name        : Rajbeer Sokhi
        StudentId   : 124969205
        Email       : rsokhi1@myseneca.ca
        Section     : NBB
        Date        : 20th January 2022
*/
#include <iostream>
#include <iomanip>
#include "foodorder.h"
using namespace std;
double g_taxrate;
double g_dailydiscount;
namespace sdds
{
    int FoodOrder::m_counter = 0;
    FoodOrder::FoodOrder() 
    {
        m_custName[0] = '\0';
        m_foodDesc[0] = '\0';
        m_price = 0.0;
    }
    
    void FoodOrder::read(std::istream& istr) 
    {
        if(!istr.fail()){
            char comma,special;
            istr.getline(m_custName,10,',');
            istr.getline(m_foodDesc,25,',');
            istr>>m_price;
            istr.ignore();
            istr>>special;
            if(!istr.fail()){
                if(special == 'Y'){
                    m_isSpecial = true;
                }
                else if(special == 'N'){
                    m_isSpecial = false;
                }
            }
        }
    }
    
    void FoodOrder::display() const
    {
        m_counter++;
        if(m_custName[0] != '\0'){
            double taxed_price = 0.0;
            taxed_price = m_price * g_taxrate;
            taxed_price += m_price; 
            cout.width(2);
            cout.setf(ios::left);
            cout<<m_counter<<". ";
            cout.width(10);
            cout<<m_custName;
            cout<<"|";
            cout.width(25);
            cout<<m_foodDesc;
            cout<<"|";
            cout.width(12);
            cout<<fixed<<setprecision(2)<<taxed_price;
            cout<<"|";
            cout.unsetf(ios::left);
            if(m_isSpecial){
                cout.setf(ios::right);
                cout.width(13);
                cout<<taxed_price - g_dailydiscount;
                cout.unsetf(ios::right);
            }
            cout<<endl;

        }
        else{
            cout<<m_counter<<". No Order"<<endl;
        }
    }

    
}
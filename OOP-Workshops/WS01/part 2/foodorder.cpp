/*Workshop #1 Part #2
        Name        : Rajbeer Sokhi
        StudentId   : 124969205
        Email       : rsokhi1@myseneca.ca
        Section     : NBB
        Date        : 22nd January 2022
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "foodorder.h"
using namespace std;
double g_taxrate;
double g_dailydiscount;
namespace sdds
{
    int FoodOrder::m_counter = 0;
    FoodOrder::FoodOrder() 
    {
        setEmpty();
    }
    
    void FoodOrder::setEmpty(){
        m_custName[0] = '\0';
        m_foodDesc = nullptr;
        m_price = 0.0;
        m_isSpecial = false;
    }
    
    void FoodOrder::set(const char* foodDesc) 
    {
        m_foodDesc = new char[strlen(foodDesc) + 1];
        strcpy(m_foodDesc,foodDesc);
    }

    void FoodOrder::read(std::istream& istr) 
    {
        setEmpty();
        if(!istr.fail()){
            char special;
            string foodDesc;
            istr.getline(m_custName,10,',');
            getline(istr,foodDesc,',');
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
                set(foodDesc.c_str());
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

    FoodOrder::~FoodOrder(){
        delete [] m_foodDesc;
    }
}
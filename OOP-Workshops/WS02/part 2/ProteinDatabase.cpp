/*Workshop #2 Part #2
        Name        : Rajbeer Sokhi
        StudentId   : 124969205
        Email       : rsokhi1@myseneca.ca
        Section     : NBB
        Date        : 1st February 2022
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <fstream>
#include "ProteinDatabase.h"
using namespace std;
namespace sdds
{
    void ProteinDatabase::setEmpty() 
    {
        m_protein = nullptr;
        m_size = 0;
    }

    ProteinDatabase::ProteinDatabase() 
    {
        setEmpty();
    }
    
    
    size_t ProteinDatabase::size() const
    {
        return m_size;
    }
    
    ProteinDatabase::~ProteinDatabase() 
    {
        delete [] m_protein;
    }
    
    ProteinDatabase::ProteinDatabase(const ProteinDatabase& P) 
    {
        setEmpty();
        *this = P;
    }
    
    string ProteinDatabase::operator[](size_t index) const
    {
        string temp ="";
        if(index < m_size){
            temp = m_protein[index];
        }
        return temp;
    }

 
    ProteinDatabase::ProteinDatabase(const string filename)
	{
		ifstream fstr(filename);
		setEmpty();
		if (fstr.is_open()){

            string temp, name;

            while (getline(fstr, temp)){
                if (temp[0] == '>') {
                    m_size++;
                }
            }
            fstr.clear();
            fstr.seekg(0);
            m_protein = new string[m_size];
            temp.clear();
            int i = -1;
            while (getline(fstr, temp).good()) {
                if (temp[0] == '>') {
                    ++i;
                    name = temp.substr('\n');
                }
                else if (!name.empty()){
                    m_protein[i] += temp;
                }
            }
        }
        fstr.close();
	}
    
    ProteinDatabase::ProteinDatabase(ProteinDatabase&& P) 
    {
        operator=(move(P));
    }
    
    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& P) 
    {
        if(this != &P){
            delete [] m_protein;
            m_size = P.m_size;
            m_protein = new string[m_size];
            for(size_t i = 0;i<m_size;i++){
                m_protein[i] = P.m_protein[i];
            }
        }
        return *this;
    }
    
    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& P) 
    {
        if(this != &P){
            m_protein = new string[P.m_protein->size()];
            delete [] m_protein;
            m_protein = P.m_protein;
            P.m_protein = nullptr;
            m_size = P.m_size;
            P.m_size = 0;
        }
        return *this;
    }
    
}
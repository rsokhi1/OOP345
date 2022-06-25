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
    
    std::string ProteinDatabase::operator[](size_t index) const
    {
        string temp ="";
        if(index < m_size){
            temp = m_protein[index];
        }
        return temp;
    }

    ProteinDatabase::ProteinDatabase(const string filename) 
    {
        if(!filename.empty()){
            string temp,protein;
            m_size = 0 ;
            ifstream fstr(filename);
            if(fstr.is_open()){
                while(getline(fstr,temp,'>')){
                    m_size++;
                }
                if(m_size > 0){
                    fstr.clear();
                    fstr.seekg(0);
                    temp.clear();
                    m_protein = new string[m_size];
                    size_t i = 0;
                    while(getline(fstr,temp).good()){
                        if(temp[0] == '>'){
                            i++;
                            protein = temp.substr('\n');
                        }
                        else if(!protein.empty()){
                            m_protein[i] += temp;
                        }
                    }
                }
            }
            fstr.close();
        }
        else{
            setEmpty();
        }
    }
    
}
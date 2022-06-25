#include <fstream>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include "CovidCollection.h"
using namespace std;
namespace sdds{

    std::string CovidCollection::removeSpaces(std::string str) {
        std::string newStr = "";
        std::string spaces = "";

        for (unsigned int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                spaces += ' ';
            } else if (str[i] == '\r' || str[i] == '\n') {
                break;
            } else {
                newStr += spaces + str[i];
                spaces = "";
            }
        }

        return newStr;
        
    }
    
    CovidCollection::CovidCollection(std::string filename)
    {
        ifstream file(filename);
        string temp{};
        if (file.is_open()){
            while(getline(file,temp)){
                Covid *t_covid = new Covid();
                t_covid->m_country = temp.substr(0,25);
                t_covid->m_city = temp.substr(25,25);
                t_covid->m_variant = temp.substr(50,25);
                t_covid->m_year = stoi(temp.substr(75,5));
                t_covid->m_noOfCases = stoi(temp.substr(80,5));
                t_covid->m_deaths = stoi(temp.substr(85,5));

                t_covid->m_country = removeSpaces(t_covid->m_country.c_str());
                t_covid->m_city = removeSpaces(t_covid->m_city.c_str());
                t_covid->m_variant = removeSpaces(t_covid->m_variant.c_str());                
                m_covidList.emplace_back(t_covid);
            }
        }
        else{
            throw std::invalid_argument("Invalid File Name");
        }
    }



std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
    out << std::left << "| " << std::setw(21) << theCovid.m_country << " | ";
    out << std::setw(15) << theCovid.m_city << " | ";
    out << std::setw(20) << theCovid.m_variant << " | ";
    out << std::right << std::setw(6) << (theCovid.m_year >= 0 ? std::to_string(theCovid.m_year) : "") << " | ";
    out << std::setw(4) << theCovid.m_noOfCases << " | ";
    out << std::setw(3) << theCovid.m_deaths << " |";

    return out;
}

void CovidCollection::display(std::ostream& out) const {
    std::for_each(m_covidList.begin(), m_covidList.end(), [&out](const Covid* theCovid) {
        out << *theCovid << std::endl;
    });
}

CovidCollection::~CovidCollection() {
    for (auto it = m_covidList.begin(); it != m_covidList.end(); it++) {
        delete *it;
    }
}

void sdds::CovidCollection::sort(std::string type) {
    std::sort(m_covidList.begin(), m_covidList.end(), [type](Covid* a, Covid *b) {
        if (type == "country") {
            return a->m_country < b->m_country;
        } else if (type == "variant") {
            return a->m_variant < b->m_variant;
        } else if (type == "cases") {
            return a->m_noOfCases < b->m_noOfCases;
        } else {
            return a->m_deaths < b->m_deaths;
        }
    });
}

void sdds::CovidCollection::cleanList() {
    std::for_each(m_covidList.begin(), m_covidList.end(), [](Covid* theCovid) {
        if (theCovid->m_variant == "[None]") {
            theCovid->m_variant = "";
        }
    });
}

bool sdds::CovidCollection::inCollection(std::string variant) const {
    return std::find_if(m_covidList.begin(), m_covidList.end(), [variant](Covid* theCovid) {
        return theCovid->m_variant == variant;
    }) != m_covidList.end();
}

std::list<sdds::Covid> sdds::CovidCollection::getListForCountry(std::string country) const {
    std::list<Covid> list;
    std::for_each(m_covidList.begin(), m_covidList.end(), [&list, country](Covid* theCovid) {
        if (theCovid->m_country == country) {
            list.emplace_back(*theCovid);
        }
    });
    return list;
}

std::list<sdds::Covid> sdds::CovidCollection::getListForVariant(std::string variant) const {
   std::list<Covid> list;
    std::for_each(m_covidList.begin(), m_covidList.end(), [&list, variant](Covid* theCovid) {
        if (theCovid->m_variant == variant) {
            list.emplace_back(*theCovid);
        }
    });
    return list;
}

}
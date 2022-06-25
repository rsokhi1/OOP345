#include<iostream>
#include <fstream>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include "CovidCollection.h"
using namespace std;

namespace sdds {
   CovidCollection::CovidCollection(const std::string str) {
      ifstream file(str);
      string line{};
      if (file.is_open()) {
         while (getline(file, line)) {
            Covid c{};
            c.m_country = line.substr(0, 25);
            c.m_city = line.substr(25, 25);
            c.m_variant = line.substr(50, 25);
            c.m_year = stoi(line.substr(75, 5));
            c.m_noOfCases = stoi(line.substr(80, 5));
            c.m_deaths = stoi(line.substr(85, 5));

            c.m_country = removeSpaces(c.m_country.c_str());
            c.m_city= removeSpaces(c.m_city.c_str());
            c.m_variant = removeSpaces(c.m_variant.c_str());

            m_covid.push_back(c);
         }
      }
      else {
         throw invalid_argument("Incorrect File name");
      }
   }

   void CovidCollection::display(ostream& out) const {
      size_t cases{}, deaths{};
      for_each(m_covid.begin(), m_covid.end(), [&out,&cases,&deaths](const Covid& c_covid) {
         out << c_covid << endl;
         cases += c_covid.m_noOfCases;
         deaths += c_covid.m_deaths;
      });
      
      out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
      out << "|" << std::right << std::setw(80) << "Total Cases Around the World:  " << cases << " |" << std::endl;
      out << "|" << std::right << std::setw(80) << "Total Deaths Around the World:  " << deaths << " |" << std::endl;

      
   }

   ostream& operator<<(ostream& out, const Covid& theCovid) {
      out <<"| " << left << setw(20) << theCovid.m_country << "  | ";
      out << setw(15) << theCovid.m_city << " | ";
      out << setw(20) << theCovid.m_variant << " | ";
      if (theCovid.m_year > 0) {
         out << right << setw(6) << theCovid.m_year;
      }
      else {
         out << setw(6) << "";
      }
      out << " | ";
      out << right << setw(4) << theCovid.m_noOfCases << " | ";
      out << right << setw(3) << theCovid.m_deaths << " |";
      return out;
   }

   void CovidCollection::sort(string field) {
      std::sort(m_covid.begin(), m_covid.end(), [field](Covid& c1, Covid& c2) {
         if (field == "country") {
            return c1.m_country < c2.m_country;
         }
         else if (field == "variant") {
            return c1.m_variant < c2.m_variant;
         }
         else if (field == "cases") {
            return c1.m_noOfCases < c2.m_noOfCases;
         }
         else{
            return c1.m_deaths < c2.m_deaths;
         }
      });
   }

   void CovidCollection::cleanList() {
      for_each(m_covid.begin(), m_covid.end(), [](Covid& c1) {
         if (c1.m_variant == "[None]") {
            c1.m_variant = "";
         }
      });
   }

   bool CovidCollection::inCollection(string variant) const {
      auto flag = find_if(m_covid.begin(), m_covid.end(), [variant](const Covid& c1) {
         return c1.m_variant == variant;
      });
      return flag != m_covid.end();
   }


   std::list<sdds::Covid> sdds::CovidCollection::getListForCountry(std::string country) const {
      std::list<Covid> temp;
      std::for_each(m_covid.begin(), m_covid.end(), [&temp, country](const Covid& theCovid) {
         if (theCovid.m_country == country) {
            temp.push_back(theCovid);
         }
         });
      return temp;
   }

   std::list<sdds::Covid> sdds::CovidCollection::getListForVariant(std::string variant) const {
      std::list<Covid> temp;
      std::for_each(m_covid.begin(), m_covid.end(), [&temp, variant](const Covid& theCovid) {
         if (theCovid.m_variant == variant) {
            temp.push_back(theCovid);
         }
         });
      return temp;
   }

   /*CovidCollection::~CovidCollection() {
      for (auto it = m_covid.begin(); it != m_covid.end(); it++) {
         delete it;
      }
   }*/

   std::string CovidCollection::removeSpaces(std::string str) {
      std::string newStr = "";
      std::string spaces = "";

      for (unsigned int i = 0; i < str.length(); i++) {
         if (str[i] == ' ') {
            spaces += ' ';
         }
         else if (str[i] == '\r' || str[i] == '\n') {
            break;
         }
         else {
            newStr += spaces + str[i];
            spaces = "";
         }
      }

      return newStr;

   }
}
#include<iostream>
#include <fstream>
#include<iomanip>
#include<algorithm>
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
            c.m_noOfDeaths = stoi(line.substr(85, 5));

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
      for_each(m_covid.begin(), m_covid.end(), [&out](const Covid& c_covid) {
         out << c_covid << endl;
         });
   }

   ostream& operator<<(ostream& out, const Covid& theCovid) {
      out << left << setw(20) << theCovid.m_country << " | ";
      out << setw(15) << theCovid.m_city << " | ";
      out << setw(20) << theCovid.m_variant << " | ";
      if (theCovid.m_year > 0) {
         out << setw(6) << theCovid.m_year;
      }
      else {
         out << setw(6) << "";
      }
      out << " | ";
      out << setw(4) << theCovid.m_noOfCases << " | ";
      out << setw(3) << theCovid.m_noOfDeaths << " |";
      return out;
   }

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
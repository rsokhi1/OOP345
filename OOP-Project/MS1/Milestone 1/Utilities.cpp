// Name: Rajbeer Sokhi
// Seneca Student ID: 124969205 
// Seneca email: rsokhi1@myseneca.ca
// Date of completion: 25/03/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Utilities.h"
using namespace std;

namespace sdds {
   char Utilities::m_delimiter{};

   void Utilities::setFieldWidth(size_t newWidth) {
      if (newWidth > 0) {
         m_widthfield = newWidth;
      }
   }

   size_t Utilities::getFieldWidth() const {
      return m_widthfield;
   }

   string Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {
      string flag{};
      size_t pos{};
      pos = str.find(m_delimiter, next_pos);
      if (str[next_pos] == m_delimiter) {
         more = false;
         throw "Delimiter was found";
      }

      if (pos != string::npos) {
         more = true;
      }
      else {
         more = false;
      }

      flag = str.substr(next_pos, pos - next_pos);

      if (m_widthfield < flag.size()) {
         m_widthfield = flag.size();
      }
      next_pos = pos + 1;
      flag = trim(flag);
      return flag;
   }

   void Utilities::setDelimiter(char newDelimiter) {
      m_delimiter = newDelimiter;
   }

   char Utilities::getDelimiter() {
      return m_delimiter;
   }

   string Utilities::trim(const string& s)
   {
      size_t flag = s.find_first_not_of(' ');
      return (flag == std::string::npos) ? "" : s.substr(flag);
   }
}
// Name: Rajbeer Sokhi
// Seneca Student ID: 124969205 
// Seneca email: rsokhi1@myseneca.ca
// Date of completion: 25/03/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
using namespace std;

namespace sdds {
   size_t Station::m_widthField = 0;
   int Station::id_generator = 0;


   Station::Station(const string& str) {
      Utilities m_util{};
      size_t pos = 0;
      bool flag = true;;

      m_name = m_util.extractToken(str, pos, flag);
      m_nextSerial = stoi(m_util.extractToken(str, pos, flag));
      m_noOfItems = stoi(m_util.extractToken(str, pos, flag));
      m_widthField = m_widthField > m_util.getFieldWidth() ? m_widthField : m_util.getFieldWidth();
      m_desc = m_util.extractToken(str, pos, flag);

      m_id = ++id_generator;
   }

   const string& Station::getItemName() const {
      return m_name;
   }

   size_t Station::getNextSerialNumber() {
      return m_nextSerial++;
   }

   size_t Station::getQuantity() const {
      return m_noOfItems;
   }

   void Station::updateQuantity() {
      if (m_noOfItems > 0) {
         m_noOfItems--;
      }
   }

   void Station::display(ostream& ostr, bool full) const {
      ostr.width(3);
      ostr.setf(ios::right);
      ostr << setfill('0') << m_id << " | ";
      ostr.fill(' ');
      ostr.unsetf(ios::right);
      ostr.width(m_widthField);
      ostr.setf(ios::left);
      ostr << m_name << " | ";
      ostr.unsetf(ios::left);
      ostr.width(6);
      ostr.setf(ios::right);
      ostr << setfill('0') << m_nextSerial << " | ";
      if (full) {
         ostr.fill(' ');
         ostr.unsetf(ios::right);
         ostr.width(4);
         ostr.setf(ios::right);
         ostr << m_noOfItems << " | ";
         ostr.unsetf(ios::right);
         ostr.setf(ios::left);
         ostr << m_desc;
         ostr.unsetf(ios::left);
      }
      ostr << endl;
   }
}
// Name: Rajbeer Sokhi
// Seneca Student ID: 124969205 
// Seneca email: rsokhi1@myseneca.ca
// Date of completion: 25/03/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H_
#define SDDS_STATION_H_
#include "Utilities.h"
namespace sdds {
   class Station {
      int m_id{};
      std::string m_name{};
      std::string m_desc{};
      unsigned int m_nextSerial{};
      unsigned int m_noOfItems{};
      static size_t m_widthField;
      static int id_generator;
   public:
      Station(const std::string& str);
      const std::string& getItemName() const;
      size_t getNextSerialNumber();
      size_t getQuantity() const;
      void updateQuantity();
      void display(std::ostream& os, bool full) const;
   };
}

#endif // !SDDS_STATION_H_
#ifndef SDDS_COVIDCOLLECTION_H_
#define SDDS_COVIDCOLLECTION_H_
#include <string>
#include <vector>
#include <list>
namespace sdds {
   struct Covid {
      std::string m_country{};
      std::string m_city{};
      std::string m_variant{};
      size_t m_noOfCases{};
      int m_year{};
      size_t m_deaths{};
   };

   class CovidCollection
   {
      std::vector<Covid> m_covid;
      std::string removeSpaces(std::string str);
   public:
      CovidCollection(const std::string str);
      void display(std::ostream& out) const;
      void sort(std::string field);
      void cleanList();
      bool inCollection(std::string variant) const;
      std::list<Covid> getListForCountry(const std::string country) const;
      std::list<Covid> getListForVariant(const std::string variant) const;
      //~CovidCollection();
   };
   std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}

#endif // !SDDS_COVIDCOLLECTION_H_

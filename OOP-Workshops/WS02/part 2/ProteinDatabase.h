/*Workshop #2 Part #2
        Name        : Rajbeer Sokhi
        StudentId   : 124969205
        Email       : rsokhi1@myseneca.ca
        Section     : NBB
        Date        : 1st February 2022
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_
#include <string>
namespace sdds{
    class ProteinDatabase{
        std::string* m_protein{};
        size_t m_size{};
        void setEmpty();
    public:
        ProteinDatabase();
        ProteinDatabase(const std::string filename);
        size_t size() const;
        std::string operator[](size_t index) const;
        ~ProteinDatabase();
        ProteinDatabase(const ProteinDatabase& P);
        ProteinDatabase(ProteinDatabase&& P);
        ProteinDatabase& operator=(const ProteinDatabase& P);
        ProteinDatabase& operator=(ProteinDatabase&& P);
        
    };
}
#endif // !SDDS_PROTEINDATABASE_H_
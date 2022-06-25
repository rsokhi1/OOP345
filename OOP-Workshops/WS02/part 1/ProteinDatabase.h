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
    };
}
#endif // !SDDS_PROTEINDATABASE_H_
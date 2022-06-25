#ifndef SDDS_TOY_H_
#define SDDS_TOY_H_
#include<string>
namespace sdds{
    class Toy{
        unsigned int m_orderId{};
        std::string m_name{};
        unsigned int m_numItems{};
        double m_price{};
        double m_tax{};
    public:
        Toy();
        void update(int numItems);
        Toy(const std::string& toy);
        friend std::ostream& operator<<(std::ostream& ostr, const Toy& t);
    };
}

#endif // !SDDS_TOY_H_
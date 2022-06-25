#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_
#include<iostream>
namespace sdds {
    class Pair
    {
        std::string m_key{};
        std::string m_value{};
    public:
        const std::string& getKey() { return m_key; }
        const std::string& getValue(){ return m_value; }
        Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};
        // TODO: Add here the missing the prototypes for the members
        //           that are necessary if this class is to be used
        //           with the template classes described below.
        //       Implement them in the Pair.cpp file.
        const std::string& getKeyConst()const { return m_key; }
        Pair() : m_key{ "" }, m_value{ "" }{};
        std::ostream& display(std::ostream& ostr = std::cout);
    };
    bool operator==(const Pair& lhs,const Pair& rhs);
    std::ostream& operator<<(std::ostream& ostr, Pair& P);
}
#endif // !SDDS_PAIR_H_
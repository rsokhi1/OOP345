/*Workshop #4 Part #2
        Name        : Rajbeer Sokhi
        StudentId   : 124969205
        Email       : rsokhi1@myseneca.ca
        Section     : NBB
        Date        : 15th February 2022
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
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
        //Toy& operator=(const Toy& T);
        void update(int numItems);
        Toy(const std::string& toy = "");
        friend std::ostream& operator<<(std::ostream& ostr, const Toy& t);
    };
}

#endif // !SDDS_TOY_H_
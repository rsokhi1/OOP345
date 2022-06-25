/*Workshop #1 Part #1
        Name        : Rajbeer Sokhi
        StudentId   : 124969205
        Email       : rsokhi1@myseneca.ca
        Section     : NBB
        Date        : 20th January 2022
*/
#ifndef SDDS_FOODORDER_H_
#define SDDS_FOODORDER_H_
extern double g_taxrate;
extern double g_dailydiscount;
namespace sdds{
    class FoodOrder{
        char m_custName[10] {'\0'};
        char m_foodDesc[25] {'\0'};
        double m_price;
        bool m_isSpecial;
        static int m_counter;
    public:
        FoodOrder();
        void read(std::istream& istr);
        void display() const;
    };
}

#endif // !SDDS_FOODORDER_H_
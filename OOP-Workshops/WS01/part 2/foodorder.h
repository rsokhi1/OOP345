/*Workshop #1 Part #2
        Name        : Rajbeer Sokhi
        StudentId   : 124969205
        Email       : rsokhi1@myseneca.ca
        Section     : NBB
        Date        : 22nd January 2022
*/
#ifndef SDDS_FOODORDER_H_
#define SDDS_FOODORDER_H_
extern double g_taxrate;
extern double g_dailydiscount;
namespace sdds{
    class FoodOrder{
        char m_custName[10];
        char* m_foodDesc{};
        double m_price;
        bool m_isSpecial;
        static int m_counter;
    public:
        FoodOrder();
        void read(std::istream& istr);
        void display() const;
        void setEmpty();
        void set(const char* foodDesc);
        ~FoodOrder();
        char* dynRead(std::istream& istr, char delimeter = '\n');
    };
}

#endif // !SDDS_FOODORDER_H_
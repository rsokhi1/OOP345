/*Workshop #4 Part #2
        Name        : Rajbeer Sokhi
        StudentId   : 124969205
        Email       : rsokhi1@myseneca.ca
        Section     : NBB
        Date        : 15th February 2022
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CONFIRMORDER_H_
#define SDDS_CONFIRMORDER_H_
#include "Toy.h"
namespace sdds{
    class ConfirmOrder{
        const Toy** m_toy{}; 
        size_t m_size{};
    public:
        ConfirmOrder();
        ConfirmOrder& operator+=(const Toy& toy); 
        ConfirmOrder& operator-=(const Toy& toy); 
        friend std::ostream& operator<<(std::ostream& ostr,const ConfirmOrder& C);
        ConfirmOrder(const ConfirmOrder& C);
        ConfirmOrder(ConfirmOrder&& C);
        ConfirmOrder& operator=(const ConfirmOrder& C);
        ConfirmOrder& operator=(ConfirmOrder&& C);
        ~ConfirmOrder();
    };
}


#endif // !SDDS_CONFIRMORDER_H_
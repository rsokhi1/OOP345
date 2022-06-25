/*Workshop #8 Part #2
		  Name        : Rajbeer Sokhi
		  StudentId   : 124969205
		  Email       : rsokhi1@myseneca.ca
		  Section     : NBB
		  Date        : 03rd April 2022
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool validateSIN(const std::string sin) {
			int sum = 0;
			int digit = 0;
			for (int i = 0; i < sin.length(); i++)
			{
				if (((i + 1) % 2) == 0)
				{
					digit = std::stoi(sin.substr(i, 1)) * 2;
					sum += (digit < 10) ? digit : digit - 9;
				}
				else
				{
					sum += std::stoi(sin.substr(i, 1));
				}
			}
			return (sum % 10) == 0;
		}


		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(T* O) {
			list.push_back(*O);
		}

		void operator+=(std::unique_ptr<T>& O) {
			list.push_back(*O);
		}

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H

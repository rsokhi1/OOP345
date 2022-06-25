#ifndef SDDS_CENTRALUNIT_H_
#define SDDS_CENTRALUNIT_H_
#include<iostream>	
#include<fstream>
#include "Job.h"
namespace sdds {
	template <typename T>
	class CentralUnit
	{
		std::string m_type{};
		T** m_items{};
		Job* m_jobs[]{};
		size_t m_size{};
		size_t m_count{};
		char* removeWhiteSpaces(char* str);
		void read(const char* str,int);

	public:
		std::ostream& log = std::cout;
		CentralUnit(std::string m_type, const char* m_file);
		// Rule of 5
		CentralUnit(const CentralUnit& C);
		CentralUnit(CentralUnit&& C);
		CentralUnit& operator=(const CentralUnit& C);
		CentralUnit& operator=(CentralUnit&& C);
		~CentralUnit();
		 
		CentralUnit& operator+=(std::string name);
		void run(); // Check
		bool has_jobs()const;
		auto get_available_units()const;
		
	};

	template<typename T>
	char* removeWhiteSpaces(char* str) {
		int i = 0, j = 0;
		while (str[i]) {
			if (str[i] != ' ') {
				str[j++] = str[i];
			}
			i++;
		}
		str[j] = '\0';
		return str;
	}

	template<typename T>
	void CentralUnit<T>::read(const char* str,int idx) {
		std::string local_str = removeWhiteSpaces(str);
		unsigned int code;
		size_t index = local_str.find('|');
		std::string tempStr = local_str.substr(0, index);
		m_items[idx].m_brand = tempStr;

		local_str.erase(0, index + 1);
		index = local_str.find('|');
		tempStr = local_str.substr(0, index);
		m_items[idx].m_code = tempStr;

		local_str.erase(0, index + 1);
		index = local_str.find('|');
		tempStr = local_str.substr(0, index);
		try {
			code = stoi(tempStr);
		}
		catch (const std::invalid_argument& ia) {
			code = 1;
		}
		m_items[idx].m_code = code;
		
	}


	template<typename T>
	CentralUnit<T>::CentralUnit(std::string m_type, const char* m_file)
	{
		std::ifstream file(m_file);
		if (!file) {
			throw "File cannot be opened";
		}
		else {
			std::string temp;
			static int i = 0
			do {
				std::getline(file, temp);
				if (file) {
					read(temp.c_str(),i);
					i++;
				}
			} while (file);
		}

  	}

	template<typename T>
	CentralUnit<T>& CentralUnit<T>::operator+=(std::string name) {
		if (m_count < 4) {
			m_jobs[m_count] = new Job(name);
			m_count++;
		}
		else {
			throw std::string;
		}
		return *this;
	}

	template<typename T>
	void CentralUnit<T>::run() {
		for (int i = 0; i < m_size; i++) {
			if (m_count > 0) {
				if (m_items[i].run()) {
					  
				}
			}
		}
	}
}

#endif // !SDDS_CENTRALUNIT_H_


#ifndef SDDS_PROCESSOR_H_
#define SDDS_PROCESSOR_H_
#include <string>
#include "CentralUnit.h"
namespace sdds {
	class Processor
	{
		CentralUnit<Processor>* m_host{};
		std::string m_brand{};
		std::string m_code{};
		unsigned int m_power{};
		Job* m_current{};
	public:
		Processor(const CentralUnit<Processor>& host, std::string brand, std::string code, unsigned int power);
		void run();
		explicit operator bool()const;
		Processor& operator+=(Job*&);
		Job* get_current_job() const;
	};
}
#endif // !SDDS_PROCESSOR_H_


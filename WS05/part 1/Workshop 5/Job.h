#ifndef SDDS_JOB_H_
#define SDDS_JOB_H_
#include<iostream>	
#include<string>
namespace sdds {
	class Job
	{
		std::string m_title{};
		size_t m_workToBeDone{};
		size_t m_workRemaining{};
		bool m_isActive{};
	public:	
		Job(){}
		Job(std::string title);
		bool is_active()const;
		bool is_complete()const;
		std::string name()const;
		std::ostream& display(std::ostream& ostr)const;
		void operator()(unsigned int workDone);
	};
	std::ostream& operator<<(std::ostream& ostr,const Job& J);
}
#endif // !SDDS_JOB_H_
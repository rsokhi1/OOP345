#include<iostream>
#include<stdexcept>
#include "Job.h"

namespace sdds {
	Job::Job(std::string title) {
		int len = title.length();
		m_workToBeDone = (len / 10) + 1;
		m_workRemaining = m_workToBeDone;
		m_title = title;
	}

	bool Job::is_active()const {
		return m_isActive;
	}

	bool Job::is_complete()const {
		return m_workRemaining == 0;
	}

	std::string Job::name() const {
		return m_title;
	}

	std::ostream& Job::display(std::ostream& ostr)const {
		if (!is_complete()) {
			ostr << m_title << " [" << m_workRemaining << "/" << m_workToBeDone << " remaining]";// << std::endl;
		}
		return ostr;
	}

	auto Job::operator()(unsigned int workDone)->void {
		if (workDone <= m_workRemaining) {
			m_workRemaining -= workDone;
		}
		else /*if(workDone > m_workRemaining)*/ {
			m_workRemaining = 0;
			throw std::underflow_error("Work done is more than remaining work");
		}
	}

	std::ostream& operator<<(std::ostream &ostr,const Job& J) {
		return J.display(ostr);
	}
}

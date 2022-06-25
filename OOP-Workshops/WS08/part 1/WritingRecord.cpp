#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
      for (size_t i = 0; i < emp.size(); i++) {
         for (size_t j = 0; j < sal.size(); j++) {
            if (emp[i].id == sal[j].id) {
               EmployeeWage* m_ew = new EmployeeWage(emp[i].name, sal[j].salary);
               try {
                  m_ew->rangeValidator();
               }
               catch (...) {
                  delete m_ew;
                  throw;
               }
               if (activeEmp.validateSIN(emp[i].id)) {
                  activeEmp += m_ew;
               }
               else {
                  throw string{ "SIN is not valid" };
               }
               delete m_ew;
            }
         }
      }	
		
		return activeEmp;
	}
}
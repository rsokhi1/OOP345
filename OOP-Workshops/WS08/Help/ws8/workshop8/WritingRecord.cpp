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
                    EmployeeWage* ptr = new EmployeeWage(emp[i].name, sal[j].salary);
                    try {
                        ptr->rangeValidator();
                    }
                    catch (...) {
                        delete ptr;
                        throw;
                    }
                    if (!activeEmp.isValidSIN(emp[i].id)) {
                        throw std::string{ " " };
                    };
                    activeEmp += std::move(ptr);
                    delete ptr;
                }
            }
        }

        return activeEmp;
    }

    GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
        GeneratingList<EmployeeWage> activeEmp;

        for (size_t i = 0; i < emp.size(); i++) {
            for (size_t j = 0; j < sal.size(); j++) {
                if (emp[i].id == sal[j].id) {
                    std::unique_ptr<EmployeeWage> ptr(new EmployeeWage(emp[i].name, sal[j].salary));
                    ptr->rangeValidator();
                    if (!activeEmp.isValidSIN(emp[i].id)) {
                        throw std::string(" ");
                    };
                    activeEmp += std::move(ptr);
                }
            }
        }

        return activeEmp;
    }
}
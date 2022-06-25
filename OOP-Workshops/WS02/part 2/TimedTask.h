/*Workshop #2 Part #2
        Name        : Rajbeer Sokhi
        StudentId   : 124969205
        Email       : rsokhi1@myseneca.ca
        Section     : NBB
        Date        : 1st February 2022
   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_
#include <iostream>
#include <chrono>
#include <string>
namespace sdds{
    const int MAX_TASK = 10;
    class TimedTask{
        int m_noOfRecords{0};
        std::chrono::steady_clock::time_point start;
        std::chrono::steady_clock::time_point end;
        struct {
            std::string m_taskName{};
            std::string m_timeUnit{};
            std::chrono::steady_clock::duration m_duration{};
        } task[10];
    public:
        TimedTask();
        void startClock();
        void stopClock();
        void addTask(const char* taskName);
        friend std::ostream& operator<<(std::ostream& ostr,const TimedTask& T);
    };
}

#endif // !SDDS_TIMEDTASK_H_
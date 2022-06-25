#include "TimedTask.h"
#include<iomanip>
using namespace std;
namespace sdds
{
    TimedTask::TimedTask() 
    {
        m_noOfRecords = 0;

    }
    
    void TimedTask::startClock() 
    {
        start = std::chrono::steady_clock::now();
    }
    
    void TimedTask::stopClock() 
    {
        end = std::chrono::steady_clock::now();
    }
    
    void TimedTask::addTask(const char* taskName) 
    {
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        if(m_noOfRecords < MAX_TASK){
            this->task[m_noOfRecords].m_taskName = taskName;
            this->task[m_noOfRecords].m_timeUnit = "nanoseconds";
            this->task[m_noOfRecords].m_duration = duration;
            m_noOfRecords++;
        }
    }
    
    std::ostream& operator<<(std::ostream& ostr,const TimedTask& T) 
    {
        ostr<<"Execution Times:"<<endl;
        ostr<<"--------------------------"<<endl;
        for(int i = 0;i<T.m_noOfRecords;i++){
            ostr.setf(ios::left);
            ostr.width(21);
            ostr<<T.task[i].m_taskName<<" ";
            ostr.unsetf(ios::left);
            ostr.setf(ios::right);
            ostr.width(13);
            ostr<<T.task[i].m_duration.count()<<" ";
            ostr.unsetf(ios::right);
            ostr<<T.task[i].m_timeUnit<<endl;
        }
        ostr<<"--------------------------"<<endl;
        return ostr;
    }


}
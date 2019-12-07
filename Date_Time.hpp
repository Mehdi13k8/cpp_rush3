#ifndef _DATE_TIME_HPP
#define _DATE_TIME_HPP

#include <ctime>
#include <ratio>
#include <chrono>
#include "IMonitorModule.hpp"

class Date_Time: public IMonitorModule {
    public:
        Date_Time();
        int getLength();
        int getWidth();
        bool getVisible();
        std::string getTimeDate();
        std::string getTime();
        std::string getDate();
        void setLength(int length);
        void setWidth(int width);
        void setVisible(bool visible);
    protected:
        std::string _date_time;
};

#endif
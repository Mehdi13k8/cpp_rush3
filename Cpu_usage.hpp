#ifndef _CPU_USAGE_H_
#define _CPU_USAGE_H_

#include "IMonitorModule.hpp"

#include <fstream>
#include <cstring>
#include <chrono>
#include <thread>

class Process : public IMonitorModule {
    public:
        Process();
        int getLength();
        int getWidth();
        bool getVisible();
        std::string getCpuUsage();
        void setLength(int length);
        void setWidth(int width);
        void setVisible(bool visible);
    protected:
        std::string _date_time;
};

#endif
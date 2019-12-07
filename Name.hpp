
#ifndef _NAME_HPP
#define _NAME_HPP

#include "IMonitorModule.hpp"

class Name : public IMonitorModule {
    public:
        Name();
        int getLength();
        int getWidth();
        bool getVisible();
        std::string findHostname();
        std::string findUsername();
        std::string getHostname();
        std::string getUsername();
        void setLength(int length);
        void setWidth(int width);
        void setVisible(bool visible);
    protected:
        std::string _hostname;
        std::string _username;
};

#endif
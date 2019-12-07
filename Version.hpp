#ifndef _VERSION_HPP
#define _VERSION_HPP

#include "IMonitorModule.hpp"
#include "fstream"

class Version : public IMonitorModule {
    public:
        Version();
        int getLength();
        int getWidth();
        bool getVisible();
        std::string findVersion();
        std::string getVersion();
        void setLength(int length);
        void setWidth(int width);
        void setVisible(bool visible);
    protected:
        std::string _version;
};

#endif
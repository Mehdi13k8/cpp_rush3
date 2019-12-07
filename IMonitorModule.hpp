#ifndef _IMONDULE_H_
#define _IMONDULE_H_
#include <iostream>

class IMonitorModule {
     public:
        IMonitorModule() {};
        virtual int getLength() = 0;
        virtual int getWidth() = 0;
        virtual bool getVisible() = 0;
        virtual void setLength(int length) = 0;
        virtual void setWidth(int width) = 0;
        virtual void setVisible(bool visible) = 0;
    protected:
        int _length;
        int _width;
        bool _visible;
};

#endif
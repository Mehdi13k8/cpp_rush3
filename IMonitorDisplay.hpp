//
// EPITECH PROJECT, 2019
// IMonitorDisplay
// File description:
// describes a display mode of your monitor.                        
//

#ifndef _IMODISPLAY_H_
#define _IMODISPLAY_H_

class IMonitorDisplay {
    public:
        IMonitorDisplay();
        virtual ~IMonitorDisplay() = 0;
        ~virtual int getLength() = 0;
        virtual int getWidth() = 0;
        virtual int getType() = 0;
        virtual void setLength(int length) = 0;
        virtual void setWidth(int width) = 0;
        virtual void setType(int type) = 0;
    protected:
        int _length;
        int _width;
        int _type; //0 = ncurses ; 1 = sfml//
};

#endif
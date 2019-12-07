
#include "Date_Time.hpp"

Date_Time::Date_Time() {
    _date_time = getTimeDate();
    _length = 384;
    _width = 216;
    _visible = true;
}

int Date_Time::getLength() {
    return (_length);
}

int Date_Time::getWidth() {
    return (_width);
}

bool Date_Time::getVisible() {
    return (_visible);
}

std::string Date_Time::getTimeDate() {
    time_t now;
    std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
    now = std::chrono::system_clock::to_time_t(today);
    return (ctime(&now));
}

std::string Date_Time::getTime() {
    int cn  = 0;
    int a = 0;
    std::string res = "";
    std::string str = _date_time;

    for (cn; a < 3; cn++) {
        if (str[cn] == ' ')
            a += 1;
    }
    while (str[cn] != ' ') {
        res += str[cn];
        cn += 1;
    }
    return (res);
}

std::string Date_Time::getDate() {
    int cn = 0;
    int a = 0;
    std::string res = "";
    std::string str = _date_time;

    for (cn; a < 3; cn++) {
        if (str[cn] == ' ')
            a += 1;
        res += str[cn];
    }
    while (str[cn] != ' ')
        cn += 1;
    cn += 1;
    for (cn; cn != str.size() - 1; cn++) {
        res += str[cn];
    }
    return (res);
}

void Date_Time::setLength(int length) {
    _length = length;
}

void Date_Time::setWidth(int width) {
    _width = width;
}

void Date_Time::setVisible(bool visible) {
    _visible = visible;
}
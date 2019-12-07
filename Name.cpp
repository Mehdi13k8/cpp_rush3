#include "Name.hpp"
#include <unistd.h>
#include <limits.h>


Name::Name() {
    _hostname = findHostname();
    _username = findUsername();
    _length = 384;
    _width = 216;
    _visible = true;
}

int Name::getLength() {
    return (_length);
}

int Name::getWidth() {
    return (_width);
}

bool Name::getVisible() {
    return (_visible);
}

std::string Name::findHostname() {
    return (getenv("NAME"));
}


std::string Name::findUsername() {
    return (getenv("USER"));
}

std::string Name::getHostname() {
    return (_hostname);
}

std::string Name::getUsername() {
    return (_username);
}

void Name::setLength(int length) {
    _length = length;
}

void Name::setWidth(int width) {
    _width = width;
}

void Name::setVisible(bool visible) {
    _visible = visible;
}
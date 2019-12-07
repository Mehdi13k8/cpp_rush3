
#include "Version.hpp"

Version::Version() {
    _version = findVersion();
    _length = 384;
    _width = 216;
    _visible = true;
}

int Version::getLength() {
    return (_length);
}

int Version::getWidth() {
    return (_width);
}

bool Version::getVisible() {
    return (_visible);
}

std::string Version::findVersion() {

    int a = 0;
    int cn = 0;
    std::ifstream file("/etc/lsb-release", std::ios::in);
    std::string stock = "";
    std::string str = "";
    
    if (file) {
        while(!getline(file, str).eof()) {
            stock += str;
            stock += '\n';
        }
        stock[stock.size() - 1] = '\0';
        file.close();
    } else {
        std::cerr << "/etc/lsb-release" <<": No such file or directory" << std::endl;
        exit (84);
    }

    str = "";
    for (cn; a < 3; cn++) {
        if (stock[cn] == '\n')
            a += 1;
    }
    while (stock[cn] != '"')
        cn += 1;
    cn += 1;
    for (cn; stock[cn] != '"'; cn++)
        str += stock[cn];
    
    return (str);
}


std::string Version::getVersion() {
    return (_version);
}

void Version::setLength(int length) {
    _length = length;
}

void Version::setWidth(int width) {
    _width = width;
}

void Version::setVisible(bool visible) {
    _visible = visible;
}
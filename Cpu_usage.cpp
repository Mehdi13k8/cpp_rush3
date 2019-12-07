#include "Cpu_usage.hpp"

Process::Process() {
    _length = 384;
    _width = 216;
    _visible = true;
}

int Process::getLength() {
    return (_length);
}

int Process::getWidth() {
    return (_width);
}

bool Process::getVisible() {
    return (_visible);
}

void Process::setLength(int length) {
    _length = length;
}

void Process::setWidth(int width) {
    _width = width;
}

void Process::setVisible(bool visible) {
    _visible = visible;
}

void   bucle(std::string processor, std::array<std::string, 100> *retstr) {
    int x = 0;
    int i = 3;
    int xi = 0;
    char str[255][255];
    while (processor.c_str()[i] != '\0' && processor.c_str()[i] != '\n') {
        if (processor.c_str()[i] >= '0' && processor.c_str()[i] <= '9') {
            str[x][xi] += processor.c_str()[i];
            xi++;
            str[x][xi] = '\0';
            if (processor.c_str()[i + 1] ==  ' ') {
                x++;

                xi = 0;
            }
        }
        i++;
    }
    int a = 0;
    while (a < i && a < 100) {
        (*retstr)[a] = str[a];
        a++;
    }
    str[0][0] = 0;
    str[1][0] = 0;
    str[2][0] = 0;
    str[3][0] = 0;
    str[4][0] = 0;
    str[6][0] = 0;
    str[7][0] = 0;
    str[8][0] = 0;
    str[9][0] = 0;
    str[10][0] = 0;
}

std::string Process::getCpuUsage()
{
    int chillcpu = 0;
    int workcpu = 0;
    std::ifstream file("/proc/stat", std::ios::in);
    std::string str = "";
    std::string stock = "";
    chillcpu = 0;
    workcpu = 0;
    double divi = 0.0;
    std::array<std::string, 100> retstr;    
        if(file) {
            while(!getline(file, str).eof()) {
                stock += str;
                stock += '\n';
            }
            stock[stock.size() - 1] = '\0';
            file.close();
        }
        else {
            std::cerr << "/proc/stat" <<": No such file or directory" << std::endl;
            exit (84);
        }
        bucle(stock, &retstr);
        workcpu = atoi(retstr[0].c_str());
        workcpu += atoi(retstr[1].c_str());
        workcpu += atoi(retstr[2].c_str());
        chillcpu = atoi(retstr[0].c_str());
        chillcpu += atoi(retstr[1].c_str());
        chillcpu += atoi(retstr[2].c_str());
        chillcpu += atoi(retstr[3].c_str());
        chillcpu += atoi(retstr[4].c_str());
        chillcpu += atoi(retstr[5].c_str());
        chillcpu += atoi(retstr[6].c_str());
        chillcpu += atoi(retstr[7].c_str());
        chillcpu += atoi(retstr[8].c_str());
        chillcpu += atoi(retstr[9].c_str());
        chillcpu += atoi(retstr[10].c_str());
        divi = 1.0 * workcpu / chillcpu;
        divi = divi * 100;
    /*    std::cout << "got working " << workcpu << std::endl;
        std::cout << "got chillin " << chillcpu << std::endl;
        std::cout << "So it make my cpu working at " << divi << "%" << std::endl;
      */file.close();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));       
        char laststr[200];
        sprintf(laststr, "%d", chillcpu);
  //      printw(laststr);
        sprintf(laststr, "%d", workcpu);
//        printw(laststr);
    //    printw("%d", chillcpu);
    return (laststr);
}

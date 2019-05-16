#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

class Utils
{
public:
    Utils();
    static char readChar();
    static double fixDouble(string number);

};

#endif // UTILS_H

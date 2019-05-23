#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif



using namespace std;

class Utils
{
public:
    Utils();
    static char readChar();
    static double fixDouble(string number);
    inline static void clearScreen(){system(CLEAR);
};

#endif // UTILS_H

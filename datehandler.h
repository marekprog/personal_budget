#ifndef DATEHANDLER_H
#define DATEHANDLER_H
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class DateHandler
{
public:
    vector<int> normalYear{31,28,31,30,31,30,31,31,30,31,30,31};
    vector<int> leapYear{31,29,31,30,31,30,31,31,30,31,30,31};

public:
    DateHandler();
    string getCurrentDate();
    int dateToInt(string date);
    int getTimeRange(string dateBegin, string dateEnd);
    int getNumberOfdays(int month,int year);
    int getYear(string date);
    int getMonth(string date);
    int getDays(string date);
    bool isLeap(int year);
};

#endif // DATEHANDLER_H

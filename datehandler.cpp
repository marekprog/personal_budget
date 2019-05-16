#include "datehandler.h"

DateHandler::DateHandler()
{

}

string DateHandler::getCurrentDate()
{
    time_t timeNow;
    tm *datestr;
    time( & timeNow );
    string date,yr,mn,d;
    datestr=localtime(&timeNow);
    yr=to_string(datestr->tm_year+1900);
    if(datestr->tm_mon>8)
        mn=to_string(datestr->tm_mon+1);
    else
        mn="0"+to_string(datestr->tm_mon+1);
    if(datestr->tm_mday>8)
        d=to_string(datestr->tm_mday);
    else
        d="0"+to_string(datestr->tm_mday);
    date=yr+"-"+mn+"-"+d;
    return date;
}
int DateHandler::getDays(string date){
    int year,month,day,days{0};
    year=stoi(date.substr(0,4));
    month=stoi(date.substr(5,6));
    day=stoi(date.substr(8,9));

   for(int y=2000;y<year;y++){
       if(isLeap(y))
       days+=366;
       else
       days+=365;
    }
   for(int m=1;m<month;m++){
       if(isLeap(year))
           days+=leapYear[m-1];
       else {
           days+=normalYear[m-1];
       }
   }
   days+=day;


    return days;

}
int DateHandler::getNumberOfdays(int month, int year){
    if( month == 2)
    {
        if((year%400==0) || (year%4==0 && year%100!=0))
            return 29;
        else
            return 28;
    }
    //months which has 31 days
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
    ||month == 10 || month==12)
        return 31;
    else
        return 30;
}
bool DateHandler::isLeap(int year){
    if((year%400==0) || (year%4==0 && year%100!=0))
        return true;
    else
        return false;
}

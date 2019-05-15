#include "datehandler.h"
#include <time.h>
DateHandler::DateHandler()
{

}

string DateHandler::getCurrentDate()
{
    time_t timeNow;
    string date;
    timeNow=time(nullptr);
    //TODO write time to string
    return date;
}
int DateHandler::getDays(string date){
    int year,month,day,days{0};
    year=2000;
    month=1;
    day=1;

   for(int y=2000;y<year;y++){
       days+=365;
   }
   for(int m=1;m<month;m++){
       days+=normalYear[m-1];
   }
   days+=day;


    return days;

}

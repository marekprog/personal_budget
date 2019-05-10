#include <iostream>
#include "Markup.h"
#include <time.h>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    CMarkup xml;
    xml.AddElem( "ORDER" );
    xml.IntoElem();
    xml.AddElem( "ITEM" );
    xml.IntoElem();
    xml.AddElem( "SN", "132487A-J" );
    xml.AddElem( "NAME", "crank casing" );
    xml.AddElem( "QTY", "1" );

    xml.Save( "Sample.xml" );

    // declaring argument of time()
        time_t my_time = time(NULL);

    // ctime() used to give the present time
        printf("%s", ctime(&my_time));
    return 0;
}

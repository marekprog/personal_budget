#include <iostream>
#include "Markup.h"
#include <time.h>
#include <usersfile.h>
#include <usermanager.h>
using namespace std;

int mainx()
{
    cout << "Hello World!" << endl;

    UserManager userManager;
    //userManager.UserRegistration();
    //userManager.UserRegistration();
    UsersFile usersFile("filename.xml");
    //usersFile.saveUsersToFile(userManager.getUsers());
    usersFile.readUsersFromFile();

    return 0;
}

int main()
{
    CMarkup xml;
    /*xml.AddElem( "ORDER" );
    xml.IntoElem();
    xml.AddElem( "ITEM" );
    xml.IntoElem();
    xml.AddElem( "SN", "132487A-J" );
    xml.AddElem( "NAME", "crank casing" );
    xml.AddElem( "QTY", "1" );
    xml.Save( "Sample.xml" );*/

    xml.Load( "C:\\Sample.xml" );
    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("ITEM") )
    {
        xml.IntoElem();
        xml.FindElem( "SN" );
        MCD_STR strSN = xml.GetData();
        cout<<"string data"<<strSN;
        xml.FindElem( "QTY" );
        int nQty = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.OutOfElem();
    }
    return 0;
}

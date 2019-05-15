#include <iostream>
#include "Markup.h"
#include <time.h>
#include <usersfile.h>
#include <usermanager.h>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    UserManager userManager("filename.xml");
    //userManager.userRegistration();
    userManager.userLogin();
    //UsersFile usersFile("filename.xml");
    //usersFile.saveUsersToFile(userManager.getUsers());
    //usersFile.readUsersFromFile();

    return 0;
}

int mainx()
{
    CMarkup xml;
    xml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
    //xml.AddElem( "island", "Curaçao" );
    //xml.Save("wtf.xml");

    xml.Load("wtf.xml");
    xml.FindElem("island");
    cout<<xml.GetData();

    /*xml.AddElem( "ORDER" );
    xml.IntoElem();
    xml.AddElem( "ITEM" );
    xml.IntoElem();
    xml.AddElem( "SN", "132487A-J" );
    xml.AddElem( "NAME", "crank casing" );
    xml.AddElem( "QTY", "1" );
    xml.Save( "Sample.xml" );*/

    /*xml.Load( "C:\\Sample.xml" );
    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("ITEM") )
    {
        xml.IntoElem();
        xml.FindElem( "SN" );
        MCD_STR strSN = xml.GetData();
        cout<<"string data"<<strSN;
        xml.FindElem( "QTY" );
        //int nQty = atoi( MCD_2PCSZ(xml.GetData()) );
        std::string s((LPCTSTR)xml.GetData());
        xml.OutOfElem();
    }*/
    return 0;
}

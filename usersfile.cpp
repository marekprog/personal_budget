#include "usersfile.h"

UsersFile::UsersFile(string usersFile):USERS_FILENAME(usersFile){};

void UsersFile::saveUsersToFile(vector<User> usersVector)
{
    cout<<"saving file"<<endl;
    xml.AddElem("USERS");
    xml.IntoElem();
    for (int i=0;i<usersVector.size();i++)
    {
        xml.AddElem("USER");
        xml.IntoElem();
        xml.AddElem("ID",usersVector.at(i).getId());
        xml.AddElem("NAME",usersVector.at(i).getName());
        xml.AddElem("SURNAME",usersVector.at(i).getSurname());
        xml.AddElem("LOGIN",usersVector.at(i).getLogin());
        xml.AddElem("PASSWORD",usersVector.at(i).getPassword());
        xml.OutOfElem();
    }
    xml.Save(USERS_FILENAME);
}

vector<User> UsersFile::readUsersFromFile()
{
    vector<User> usersVector;
    //here I make attempt to read users from file
    xml.Load(USERS_FILENAME);
    //cout<<xml.GetResult();
    //xml.IntoElem();
    //xml.IntoElem();
   // strxml.FindElem("NAME");
    MCD_STR strSN =xml.GetData();
    cout<<strSN.size();
    //
    return usersVector;
}

#include "usersfile.h"

UsersFile::UsersFile(string usersFile):USERS_FILENAME(usersFile){}

bool UsersFile::fileExists()
{
    ifstream ifile(USERS_FILENAME.c_str());
    return ifile.good();
}

void UsersFile::saveUsersToFile(vector<User> usersVector)
{
    cout<<"saving file"<<endl;
    xml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
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
    User user;
    vector<User> usersVector;
    if (fileExists()){
        xml.Load(USERS_FILENAME);
        xml.FindElem("USERS");
        xml.IntoElem();
        while ( xml.FindElem("USER")) {
            xml.IntoElem();
            xml.FindElem("ID");
            user.setId(stoi(xml.GetData()));
            xml.FindElem("NAME");
            user.name=xml.GetData();
            xml.FindElem("SURNAME");
            user.surname=xml.GetData();
            xml.FindElem("LOGIN");
            user.login=xml.GetData();
            xml.FindElem("PASSWORD");
            user.password=xml.GetData();
            xml.OutOfElem();
            usersVector.push_back(user);
        }
        cout<<"Number of users is: "<<usersVector.size()<<endl;
        return usersVector;

    }
    else {
        return usersVector;
    }

}

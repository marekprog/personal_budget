#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User
{
    int id;
    string name;
    string surname;
    string login;
    string password;

public:
    User();
    void setId(int newId);
    void setName();
    void setSurname ();
    void setLogin ();
    void setPassword ();
    void setPassword(string newPassword);
    int getId();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();
    friend class UsersFile;
};

#endif // USER_H

#include "user.h"

User::User()
{

}
void User::setId(int newId)
{
    //cout<<"setting new Id"<<endl;
    id=newId;
};
void User::setName()
{
    cout<<"Type your name"<<endl;
    cin>>name;
}
void User::setSurname ()
{
    cout<<"Type your surname"<<endl;
    cin>>surname;
}
void User::setLogin ()
{
    cout<<"Type your login"<<endl;
    cin>>login;
}
void User::setPassword ()
{
    cout<<"Type your password"<<endl;
    cin>>password;
}
int User::getId()
{
    return id;
}
string User::getName()
{
    return name;
}
string User::getSurname()
{
    return surname;
}
string User::getLogin()
{
    return login;
}
string User::getPassword()
{
    return password;
}


#include "usermanager.h"

UserManager::UserManager()
{

}
vector<User> UserManager::getUsers()
{
    return users;
}

void UserManager::UserRegistration()
{
    User user;
    cout<<"Rejestracja Uzytkownika, podaj dane:"<<endl;
    int newId=users.size();
    user.setId(newId);
    user.setName();
    user.setSurname();
    user.setLogin();
    user.setPassword();

    users.push_back(user);

}

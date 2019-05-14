#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <vector>
#include "user.h"

class UserManager
{
    int loggedUserId;
    vector<User> users;
    //fileWithUsers plikZUzytkownikami;


    //User podajDaneNowegoUzytkownika();
    //int pobierzIdNowegoUzytkownika();
    //bool czyIstniejeLogin(string login);

public:
    UserManager();
    void UserRegistration();
    vector<User> getUsers();
};

#endif // USERMANAGER_H

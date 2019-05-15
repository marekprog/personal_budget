#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <vector>
#include "user.h"
#include "usersfile.h"

class UserManager
{
    int loggedUserId;
    vector<User> users;
    UsersFile usersFile;


    //User podajDaneNowegoUzytkownika();
    //int pobierzIdNowegoUzytkownika();
    //bool czyIstniejeLogin(string login);

public:
    UserManager(string fileWithUsers);
    void userRegistration();
    void userLogin();
    vector<User> getUsers();
};

#endif // USERMANAGER_H

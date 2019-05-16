#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <vector>
#include "user.h"
#include "usersfile.h"

class UserManager
{
    int loggedUserId{NULL};
    vector<User> users;
    UsersFile usersFile;


    //User podajDaneNowegoUzytkownika();
    //int pobierzIdNowegoUzytkownika();
    //bool czyIstniejeLogin(string login);

public:
    UserManager(string fileWithUsers);
    void userRegistration();
    void userLogin();
    void userLogout();
    void changePassword();
    vector<User> getUsers();
    int getUserLogin();
};

#endif // USERMANAGER_H

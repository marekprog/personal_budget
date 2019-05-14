#ifndef USERSFILE_H
#define USERSFILE_H
#include<xmlfile.h>
#include "user.h"
#include <vector>


class UsersFile : public XmlFile
{
    const string USERS_FILENAME;
public:
    UsersFile(string usersFilename);
    void saveUsersToFile(vector<User> usersVector);
    vector<User> readUsersFromFile();
};

#endif // USERSFILE_H

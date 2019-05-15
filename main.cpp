#include <iostream>
#include "Markup.h"
#include <time.h>
#include <usersfile.h>
#include <usermanager.h>
#include "datehandler.h"
using namespace std;

int main()
{
    UserManager userManager("filename.xml");
    DateHandler date;
    //userManager.userRegistration();
    //userManager.userLogin();
    //UsersFile usersFile("filename.xml");
    //usersFile.saveUsersToFile(userManager.getUsers());
    //usersFile.readUsersFromFile();
    //cout<<date.getDays("");
    date.getCurrentDate();
    return 0;
}


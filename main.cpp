#include <iostream>
#include "Markup.h"
#include <time.h>
#include <usersfile.h>
#include <usermanager.h>
#include "datehandler.h"
#include "transactionmanager.h"
using namespace std;

int main()
{
    UserManager userManager("filename.xml");
    DateHandler date;
    TransactionManager transaction("expenses.xml","incomes.xml");
    //userManager.userRegistration();
    //userManager.userLogin();
    //UsersFile usersFile("filename.xml");
    //usersFile.saveUsersToFile(userManager.getUsers());
    //usersFile.readUsersFromFile();
    //cout<<date.getDays("");
    date.getCurrentDate();
    cout<<date.getDays(date.getCurrentDate());
    transaction.addIncome();

    return 0;
}


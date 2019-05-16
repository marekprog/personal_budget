#include <iostream>
#include "Markup.h"
#include <time.h>
#include <usersfile.h>
#include <usermanager.h>
#include "datehandler.h"
#include "transactionmanager.h"
#include "utils.h"
using namespace std;

char mainMenu();
char userMenu();

int main()
{
    UserManager userManager("users.xml");
    DateHandler date;
    TransactionManager transaction("expenses.xml","incomes.xml");
    while(true){
        char selection;
        if (userManager.getUserLogin()==0){
            selection = mainMenu();
            switch (selection)
            {
            case '1':
                userManager.userRegistration();
                cin.get();
                break;
            case '2':
                userManager.userLogin();
                break;
            case '9':
                exit(0);
            default:
                cout << endl << "No such option." << endl << endl;
                system("pause");
                break;
            }
        }
        else {
            selection = userMenu();
            switch (selection)
            {
            case '1':
                transaction.addIncome(userManager.getUserLogin());
                break;
            case '2':
                transaction.addExpense(userManager.getUserLogin());
                break;
            case '3':
                transaction.getBalanceCurrentMonth(userManager.getUserLogin());
                break;
            case '4':
                transaction.getBalanceLastMonth(userManager.getUserLogin());
                break;
            case '5':
                transaction.getBalanceCustom(userManager.getUserLogin());
                break;
            case '6':
                userManager.changePassword();
                break;
            case '7':
                userManager.userLogout();
                break;
            }
        }
    }
    return 0;
}

char mainMenu()
{
    char selection;
    system("clear");
    cout << "    >>> PERSONAL BUDGET <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. User Registration" << endl;
    cout << "2. User Login" << endl;
    cout << "9. End Program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your selection: ";
    selection = Utils::readChar();

    return selection;
}

char userMenu()
{
    char selection;
    cin.get();
    system("clear");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month balance" << endl;
    cout << "4. Previous month balance " << endl;
    cout << "5. Balance from selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your selection: ";
    selection = Utils::readChar();

    return selection;
}




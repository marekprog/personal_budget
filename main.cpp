#include <iostream>
#include "Markup.h"
#include <time.h>
#include "usersfile.h"
#include "usermanager.h"
#include "datehandler.h"
//#include "transactionmanager.h"
#include "utils.h"
#include "budgetmanager.h"
using namespace std;

char mainMenu();
char userMenu();

int main()
{
    //UserManager userManager("users.xml");
    //DateHandler date;
    BudgetManager budget("users.xml","expenses.xml","incomes.xml");
    while(true){
        char selection;
        if (!budget.isUserLogged()){
            selection = mainMenu();
            switch (selection)
            {
            case '1':
                budget.userRegistration();
                cin.get();
                break;
            case '2':
                budget.userLogin();
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
                budget.addIncome();
                break;
            case '2':
                budget.addExpense();
                break;
            case '3':
                budget.getBalanceCurrentMonth();
                break;
            case '4':
                budget.getBalanceLastMonth();
                break;
            case '5':
                budget.getBalanceCustom();
                break;
            case '6':
                budget.changeUserPassword();
                break;
            case '7':
                budget.userLogout();
                break;
            }
        }
    }
    return 0;
}

char mainMenu()
{
    char selection;
    Utils::clearScreen();
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
    Utils::clearScreen();
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




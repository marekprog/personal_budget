#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H
#include "transactionmanager.h"
#include "usermanager.h"
#include <iostream>

using namespace std;

class BudgetManager
{
    UserManager userManager;
    DateHandler date;
    TransactionManager *transactionManager;
    const string EXPENSES_FILENAME,INCOMES_FILENAME;
public:
    BudgetManager(string usersFile,string expensesFile,string incomesFile);
    ~BudgetManager();
    void userRegistration();
    void userLogin();
    void userLogout();
    bool isUserLogged();
    void changeUserPassword();
    void addIncome();
    void addExpense();
    void getBalance(int startDate,int endDate);
    void getBalanceCurrentMonth();
    void getBalanceLastMonth();
    void getBalanceCustom();
    void printExpenses(vector<Expense> expenses);
    void printIncomes(vector<Income> expenses);
};

#endif // BUDGETMANAGER_H

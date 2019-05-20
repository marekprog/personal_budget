#include "budgetmanager.h"

BudgetManager::BudgetManager(string usersFile,string expensesFile,string incomesFile):
    userManager(usersFile),EXPENSES_FILENAME(expensesFile),INCOMES_FILENAME(incomesFile)
{
    transactionManager=nullptr;
}
BudgetManager::~BudgetManager()
{
    delete transactionManager;
    transactionManager=nullptr;
}
void BudgetManager::userRegistration()
{
    userManager.userRegistration();
}
void BudgetManager::userLogin()
{
    userManager.userLogin();
    transactionManager=new TransactionManager(EXPENSES_FILENAME,INCOMES_FILENAME,userManager.getUserLogin());

}
void BudgetManager::userLogout()
{
    userManager.userLogout();
    delete transactionManager;
    transactionManager = nullptr;
}
bool BudgetManager::isUserLogged()
{
    userManager.isLogged();
}
void BudgetManager::changeUserPassword()
{
    userManager.changePassword();
}
void BudgetManager::addIncome()
{
    transactionManager->addIncome();
}
void BudgetManager::addExpense()
{
    transactionManager->addExpense();
}
void BudgetManager::getBalanceCurrentMonth()
{
    transactionManager->getBalanceCurrentMonth();
}
void BudgetManager::getBalanceLastMonth()
{
    transactionManager->getBalanceLastMonth();
}
void BudgetManager::getBalanceCustom()
{
    transactionManager->getBalanceCustom();
}

#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H
#include "income.h"
#include "expense.h"
#include <vector>
#include "expensesfile.h"
#include "incomesfile.h"
#include "datehandler.h"
#include <algorithm>

class TransactionManager
{
    //const int LOGGED_USER_ID;
    vector<Income> incomes;
    vector<Expense> expenses;
    ExpensesFile expensesFile;
    IncomesFile incomesFile;
    DateHandler dateHandler;



public:
    TransactionManager(string fileWithExpenses,string fileWithIncomes);
    void readIncomesFromFile();
    void readExpensesFromFile();
    void addIncome(int loggedUserId);
    void addExpense(int loggedUserId);
    void getBalance(int startDate,int endDate,int loggedUserId);
    void getBalanceCurrentMonth(int loggedUserId);
    void getBalanceLastMonth(int loggedUserId);
    void getBalanceCustom(int loggedUserId);
    void printExpenses(vector<Expense> expenses);
    void printIncomes(vector<Income> expenses);

};

#endif // TRANSACTIONMANAGER_H

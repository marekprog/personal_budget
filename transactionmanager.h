#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H
#include "income.h"
#include "expense.h"
#include <vector>
#include "expensesfile.h"
#include "incomesfile.h"
#include "datehandler.h"
#include <algorithm>
#include "utils.h"

class TransactionManager
{
    const int LOGGED_USER_ID;
    vector<Income> incomes;
    vector<Expense> expenses;
    ExpensesFile expensesFile;
    IncomesFile incomesFile;
    DateHandler dateHandler;



public:
    TransactionManager(string fileWithExpenses,string fileWithIncomes,int loggedUserId);
    void readIncomesFromFile();
    void readExpensesFromFile();
    void addIncome();
    void addExpense();
    void getBalance(int startDate,int endDate);
    void getBalanceCurrentMonth();
    void getBalanceLastMonth();
    void getBalanceCustom();
    void printExpenses(vector<Expense> expenses);
    void printIncomes(vector<Income> expenses);

};

#endif // TRANSACTIONMANAGER_H

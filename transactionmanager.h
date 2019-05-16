#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H
#include "income.h"
#include "expense.h"
#include <vector>
#include "expensesfile.h"
#include "incomesfile.h"
#include "datehandler.h"

class TransactionManager
{
    //const int LOGGED_USER_ID;
    vector<Income> incomes;
    vector<Expense> expenses;
    ExpensesFile expensesFile;
    IncomesFile incomesFile;
    DateHandler dateHandler;

    void readIncomesFromFile(int loggedUserId);
    void readExpensesFromFile(int loggedUserId);

public:
    TransactionManager(string fileWithExpenses,string fileWithIncomes);
    void addIncome();
    void addExpense();
    void getBalanceCurrentMonth();
    void getBalancePreviousMonth();
    void getBalanceCustom(int startDate,int endDate);
};

#endif // TRANSACTIONMANAGER_H

#ifndef EXPENSE_H
#define EXPENSE_H
#include "transaction.h"

class Expense : public Transaction
{
    map <int,string> itemList =
    {
        {1,"bills"},
        {2,"leisure"},
        {3,"misc"}
    };
    string item;
public:
    Expense();
    void printMap();
    friend class TransactionManager;
    friend class ExpensesFile;
};


#endif // EXPENSE_H

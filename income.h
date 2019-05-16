#ifndef INCOME_H
#define INCOME_H
#include "transaction.h"

class Income: public Transaction
{
    map <int,string> itemList =
    {
        {1,"salary"},
        {2,"upwork"},
        {3,"misc"}
    };
    string item;

public:
    Income();
    void printMap();
    friend class TransactionManager;
    friend class IncomesFile;
};

#endif // INCOME_H

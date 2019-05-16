#ifndef INCOME_H
#define INCOME_H
#include "transaction.h"

class Income: public Transaction
{
    map <int,string> itemlist =
    {
        {1,"salary"},
        {2,"upwork"},
        {3,"misc"}
    };
    string item;

public:
    Income();
    friend class TransactionManager;
    friend class IncomesFile;
};

#endif // INCOME_H

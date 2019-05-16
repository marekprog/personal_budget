#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<iostream>
#include <map>

using namespace std;

class Transaction
{
    int transactionId;
    int userId;
    string date;
    int dayNr;
    map<int,string> item;
    double amount;

public:
    Transaction();
    friend class TransactionManager;
    friend class IncomesFile;
    friend class ExpensesFile;
};

#endif // TRANSACTION_H

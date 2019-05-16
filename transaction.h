#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<iostream>
#include <map>

using namespace std;

class Transaction
{
protected:
    int transactionId;
    int userId;
    string date;
    int dayNr;
    map<int,string> itemList;
    double amount;
    string item;

public:
    Transaction();
    void printMap();
    friend class TransactionManager;
    friend class IncomesFile;
    friend class ExpensesFile;
};

#endif // TRANSACTION_H

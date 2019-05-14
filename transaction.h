#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<iostream>

using namespace std;

class Transaction
{
    int transactionId;
    int userId;
    string date;
    int dayNr;
    //enum item;
    double amount;

public:
    Transaction();
};

#endif // TRANSACTION_H

#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H
#include "xmlfile.h"
#include <vector>
#include "expense.h"

class ExpensesFile : public XmlFile
{
    const string EXPENSES_FILENAME;
public:
    ExpensesFile(string expensesFilename);
    void saveExpensesToFile(vector<Expense> expensesVector);
    vector<Expense> readExpensesFromFile();
};

#endif // EXPENSESFILE_H

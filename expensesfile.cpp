#include "expensesfile.h"

ExpensesFile::ExpensesFile(string expensesFilename):EXPENSES_FILENAME(expensesFilename){};

void ExpensesFile::saveExpensesToFile(vector<Expense> expensesVector)
{
    cout<<"saving file"<<endl;
    xml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
    xml.AddElem("INCOMES");
    xml.IntoElem();
    for (int i=0;i<expensesVector.size();i++)
    {
        xml.AddElem("INCOME");
        xml.IntoElem();
        xml.AddElem("DATE",expensesVector.at(i).date);
        xml.AddElem("DAYNR",expensesVector.at(i).dayNr);
        xml.AddElem("AMOUNT",expensesVector.at(i).amount);//TODO fix implicit conversion
        xml.AddElem("ITEM",expensesVector.at(i).item);
        xml.AddElem("USERID",expensesVector.at(i).userId);
        xml.AddElem ("TRANSACTIONID",expensesVector.at(i).transactionId);
        xml.OutOfElem();
    }
    xml.Save(EXPENSES_FILENAME);
}

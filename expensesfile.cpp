#include "expensesfile.h"

ExpensesFile::ExpensesFile(string expensesFilename):EXPENSES_FILENAME(expensesFilename){};

bool ExpensesFile::fileExists()
{
    ifstream ifile(EXPENSES_FILENAME.c_str());
    return ifile.good();
}

void ExpensesFile::saveExpensesToFile(vector<Expense> expensesVector)
{
    cout<<"saving expenses file"<<endl;
    xml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
    xml.AddElem("EXPENSES");
    xml.IntoElem();
    for (int i=0;i<expensesVector.size();i++)
    {
        xml.AddElem("EXPENSE");
        xml.IntoElem();
        xml.AddElem("DATE",expensesVector.at(i).date);
        xml.AddElem("DAYNR",expensesVector.at(i).dayNr);
        xml.AddElem("AMOUNT",expensesVector.at(i).amount*100);
        xml.AddElem("ITEM",expensesVector.at(i).item);
        xml.AddElem("USERID",expensesVector.at(i).userId);
        xml.AddElem ("TRANSACTIONID",expensesVector.at(i).transactionId);
        xml.OutOfElem();
    }
    xml.Save(EXPENSES_FILENAME);
}


vector<Expense> ExpensesFile::readExpensesFromFile()
{
    Expense expense;
    vector<Expense> expensesVector;
    if (fileExists()){
        xml.Load(EXPENSES_FILENAME);
        xml.FindElem("EXPENSES");
        xml.IntoElem();
        while ( xml.FindElem("EXPENSE")) {
            xml.IntoElem();
            xml.FindElem("DATE");
            expense.date=xml.GetData();
            xml.FindElem("DAYNR");
            expense.dayNr=stoi(xml.GetData());
            xml.FindElem("AMOUNT");
            expense.amount=stoi(xml.GetData())/100;
            xml.FindElem("ITEM");
            expense.item=xml.GetData();
            xml.FindElem("USERID");
            expense.userId=stoi(xml.GetData());
            xml.FindElem("TRANSACTIONID");
            expense.transactionId=stoi(xml.GetData());
            xml.OutOfElem();
            expensesVector.push_back(expense);
        }
        cout<<"Number of expenses is: "<<expensesVector.size()<<endl;
        return expensesVector;

    }
    else {
        return expensesVector;
    }

}

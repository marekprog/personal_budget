#include "incomesfile.h"

IncomesFile::IncomesFile(string incomesFilename):INCOMES_FILENAME(incomesFilename){}

bool IncomesFile::fileExists()
{
    ifstream ifile(INCOMES_FILENAME.c_str());
    return ifile.good();
}

void IncomesFile::saveIncomesToFile(vector<Income> incomesVector)
{
    cout<<"saving incomes file"<<endl;
    xml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
    xml.AddElem("INCOMES");
    xml.IntoElem();
    for (int i=0;i<incomesVector.size();i++)
    {
        xml.AddElem("INCOME");
        xml.IntoElem();
        xml.AddElem("DATE",incomesVector.at(i).date);
        xml.AddElem("DAYNR",incomesVector.at(i).dayNr);
        xml.AddElem("AMOUNT",incomesVector.at(i).amount*100);
        xml.AddElem("ITEM",incomesVector.at(i).item);
        xml.AddElem("USERID",incomesVector.at(i).userId);
        xml.AddElem ("TRANSACTIONID",incomesVector.at(i).transactionId);
        xml.OutOfElem();
    }
    xml.Save(INCOMES_FILENAME);
}

vector<Income> IncomesFile::readIncomesFromFile()
{
    Income income;
    vector<Income> incomesVector;
    if (fileExists()){
        xml.Load(INCOMES_FILENAME);
        xml.FindElem("INCOMES");
        xml.IntoElem();
        while ( xml.FindElem("INCOME")) {
            xml.IntoElem();
            xml.FindElem("DATE");
            income.date=xml.GetData();
            xml.FindElem("DAYNR");
            income.dayNr=stoi(xml.GetData());
            xml.FindElem("AMOUNT");
            income.amount=stoi(xml.GetData())/100;
            xml.FindElem("ITEM");
            income.item=xml.GetData();
            xml.FindElem("USERID");
            income.userId=stoi(xml.GetData());
            xml.FindElem("TRANSACTIONID");
            income.transactionId=stoi(xml.GetData());
            xml.OutOfElem();
            incomesVector.push_back(income);
        }
        cout<<"Number of incomes is: "<<incomesVector.size()<<endl;
        return incomesVector;

    }
    else {
        return incomesVector;
    }

}

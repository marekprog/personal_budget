#include "incomesfile.h"

IncomesFile::IncomesFile(string incomesFilename):INCOMES_FILENAME(incomesFilename){};

void IncomesFile::saveIncomesToFile(vector<Income> incomesVector)
{
    cout<<"saving file"<<endl;
    xml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
    xml.AddElem("INCOMES");
    xml.IntoElem();
    for (int i=0;i<incomesVector.size();i++)
    {
        xml.AddElem("INCOME");
        xml.IntoElem();
        xml.AddElem("DATE",incomesVector.at(i).date);
        xml.AddElem("DAYNR",incomesVector.at(i).dayNr);
        xml.AddElem("AMOUNT",incomesVector.at(i).amount);//TODO fix implicit conversion
        xml.AddElem("ITEM",incomesVector.at(i).item);
        xml.AddElem("USERID",incomesVector.at(i).userId);
        xml.AddElem ("TRANSACTIONID",incomesVector.at(i).transactionId);
        xml.OutOfElem();
    }
    xml.Save(INCOMES_FILENAME);
}


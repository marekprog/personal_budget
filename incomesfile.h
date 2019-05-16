#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include "xmlfile.h"
#include "income.h"
#include <vector>

class IncomesFile:public XmlFile
{
    const string INCOMES_FILENAME;
public:
    IncomesFile(string incomesFilename);
    void saveIncomesToFile(vector<Income> incomesVector);
    vector<Income> readIncomesFromFile();
    bool fileExists();

};

#endif // INCOMESFILE_H

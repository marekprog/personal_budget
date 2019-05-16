#ifndef XMLFILE_H
#define XMLFILE_H
#include "Markup.h"
#include <iostream>
#include <fstream>

using namespace std;

class XmlFile
{
    const string FILE_NAME;

public:
    XmlFile();
    XmlFile(string fileName);
protected:
    virtual bool fileExists()=0;
    CMarkup xml;

};

#endif // XMLFILE_H

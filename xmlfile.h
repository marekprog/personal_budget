#ifndef XMLFILE_H
#define XMLFILE_H
#include "Markup.h"
#include <iostream>

using namespace std;

class XmlFile
{
    const string FILE_NAME;

public:
    XmlFile();
    XmlFile(string fileName);
protected:
    bool fileExists();
    CMarkup xml;

};

#endif // XMLFILE_H

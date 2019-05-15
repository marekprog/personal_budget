#include "xmlfile.h"

XmlFile::XmlFile(string fileName):FILE_NAME(fileName){};

XmlFile::XmlFile():FILE_NAME("textxml.xml"){};

bool XmlFile::fileExists()
{
    //TODO: write the actual function
    cout<<"file opened succesfully"<<endl;
    return true;
}

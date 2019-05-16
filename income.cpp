#include "income.h"

Income::Income()
{

}
void Income::printMap()
{
    cout<<endl;
    for (auto const& x : itemList)
    {
       cout << x.first  // string (key)
       << ". "
       << x.second // string's value
       << endl ;
    }
}

#include "transaction.h"

Transaction::Transaction()
{

}

void Transaction::printMap()
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

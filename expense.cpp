#include "expense.h"

Expense::Expense()
{

}
void Expense::printMap()
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

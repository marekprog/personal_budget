#include "transactionmanager.h"

TransactionManager::TransactionManager(string fileWithExpenses,string fileWithIncomes):expensesFile(fileWithExpenses),incomesFile(fileWithIncomes)
{

}

void TransactionManager::addIncome()
{
    Income income;
    income.date=dateHandler.getCurrentDate();//TODO add prompt to ask what date
    income.dayNr=dateHandler.getDays(dateHandler.getCurrentDate());
    income.item=income.itemlist[1];//TODO: add prompt here
    income.amount=1400.50;//TODO: add prompt here
    income.userId=1;
    income.transactionId=incomes.size();

    incomes.push_back(income);
    incomesFile.saveIncomesToFile(incomes);
}

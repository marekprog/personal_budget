#include "transactionmanager.h"

TransactionManager::TransactionManager(string fileWithExpenses,string fileWithIncomes,int loggedUserId):
    expensesFile(fileWithExpenses),incomesFile(fileWithIncomes),LOGGED_USER_ID(loggedUserId)
{
    incomes=incomesFile.readIncomesFromFile();
    expenses=expensesFile.readExpensesFromFile();
}

void TransactionManager::addIncome()
{
    Income income;
    int selectDate;
    string customDate;
    cout<<"Select Option:"<<endl;
    cout<<"(1) Use todays date or (2) Type date:"<<endl;
    cin>>selectDate;
    cout<<"YOU have selected: "<<selectDate<<endl;
    if (selectDate==1){
        income.date=dateHandler.getCurrentDate();
        income.dayNr=dateHandler.getDays(dateHandler.getCurrentDate());
    }
    else if(selectDate==2){
        do{
        cout<<"Enter Date in format 'yyyy-mm-dd': ";
        cin>>customDate;
        }while(dateHandler.checkDate(customDate)!=1);
        income.date=customDate;
        income.dayNr=dateHandler.getDays(customDate);
        income.date=customDate;
        income.dayNr=dateHandler.getDays(customDate);
    }
    cout<<"add category"<<endl;
    income.printMap();
    int selectCat;
    cin>>selectCat;
    income.item=income.itemList[selectCat];
    cout<<"Enter amount: ";
    string am;
    cin>>am;
    income.amount=Utils::fixDouble(am);
    income.userId=LOGGED_USER_ID;
    income.transactionId=incomes.size();

    incomes.push_back(income);
    incomesFile.saveIncomesToFile(incomes);
}

void TransactionManager::addExpense()
{
    Expense expense;
    int selectDate;
    string customDate;
    cout<<"Select Option:"<<endl;
    cout<<"(1) Use todays date or (2) Type date:"<<endl;
    cin>>selectDate;
    cout<<"You have selected: "<<selectDate<<endl;
    if (selectDate==1){
        expense.date=dateHandler.getCurrentDate();
        expense.dayNr=dateHandler.getDays(dateHandler.getCurrentDate());
    }
    else if(selectDate==2){
        do{
        cout<<"Enter Date in format 'yyyy-mm-dd': ";
        cin>>customDate;
        }while(dateHandler.checkDate(customDate)!=1);
        expense.date=customDate;
        expense.dayNr=dateHandler.getDays(customDate);
        expense.date=customDate;
        expense.dayNr=dateHandler.getDays(customDate);
    }

    cout<<"add category"<<endl;
    expense.printMap();
    int selectCat;
    cin>>selectCat;
    expense.item=expense.itemList[selectCat];
    cout<<"Enter amount: ";
    string am;
    cin>>am;
    expense.amount=Utils::fixDouble(am);
    expense.userId=LOGGED_USER_ID;
    expense.transactionId=expenses.size();

    expenses.push_back(expense);
    expensesFile.saveExpensesToFile(expenses);
}

void TransactionManager::readIncomesFromFile()
{
    incomes=incomesFile.readIncomesFromFile();
}

void TransactionManager::readExpensesFromFile()
{
    expenses=expensesFile.readExpensesFromFile();
}

void TransactionManager::printExpenses(vector<Expense> transactions)
{
    cout<<"EXPENSES:"<<endl;
    cout.setf(ios::left);
        cout.width(15);
        cout<<"DATE";
        cout.width(10);
        cout<<"DAYNR";
        cout.width(15);
        cout<<"AMOUNT";
        cout.width(15);
        cout<<"ITEM";
        cout.width(10);
        cout<<"USERID";
        cout.width(15);
        cout<<"TRANSACTIONID"<<endl;

        for(int i=0;i<transactions.size();i++)
        {

            cout.width(15);
            cout<<transactions.at(i).date;
            cout.width(10);
            cout<<transactions.at(i).dayNr;
            cout.width(15);
            cout<<transactions.at(i).amount;
            cout.width(15);
            cout<<transactions.at(i).item;
            cout.width(10);
            cout<<transactions.at(i).userId;
            cout.width(15);
            cout<<transactions.at(i).transactionId<<endl;
        }
        cout<<"------------------------------"<<endl;
}

void TransactionManager::printIncomes(vector<Income> transactions)
{
    cout<<"INCOMES:"<<endl;
    cout.setf(ios::left);
        cout.width(15);
        cout<<"DATE";
        cout.width(10);
        cout<<"DAYNR";
        cout.width(15);
        cout<<"AMOUNT";
        cout.width(15);
        cout<<"ITEM";
        cout.width(10);
        cout<<"USERID";
        cout.width(15);
        cout<<"TRANSACTIONID"<<endl;

        for(int i=0;i<transactions.size();i++)
        {

            cout.width(15);
            cout<<transactions.at(i).date;
            cout.width(10);
            cout<<transactions.at(i).dayNr;
            cout.width(15);
            cout<<transactions.at(i).amount;
            cout.width(15);
            cout<<transactions.at(i).item;
            cout.width(10);
            cout<<transactions.at(i).userId;
            cout.width(15);
            cout<<transactions.at(i).transactionId<<endl;
        }
        cout<<"------------------------------"<<endl;
}

void TransactionManager::getBalance(int startDate, int endDate)
{
    //some local helping variables here
    vector<Expense> lExpenses;
    vector<Income> lIncomes;
    double sumExp{0},sumInc{0};
    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if (itr->dayNr >= startDate && itr->dayNr<=endDate &&itr->userId==LOGGED_USER_ID)
        {
            lExpenses.push_back(*itr);
            sumExp+=itr->amount;
        }
    }
    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if (itr->dayNr >= startDate && itr->dayNr<=endDate &&itr->userId==LOGGED_USER_ID)
        {
            lIncomes.push_back(*itr);
            sumInc+=itr->amount;
        }
    }
    //sort
    sort(lIncomes.begin(), lIncomes.end(), [](const Income& lhs, const Income& rhs) {
          return lhs.dayNr < rhs.dayNr;
       });
    sort(lExpenses.begin(), lExpenses.end(), [](const Expense& lhs, const Expense& rhs) {
             return lhs.dayNr < rhs.dayNr;
          });
    printExpenses(lExpenses);
    printIncomes(lIncomes);
    cout<<"Total expenses for selected period: "<<sumExp<<endl;
    cout<<"Total incomes for selected period: "<<sumInc<<endl;
    cout<<"Balance for the selected period: "<<sumInc-sumExp<<endl;
}

void TransactionManager::getBalanceCurrentMonth()
{
    string dateStart=dateHandler.getCurrentDate();
    string dateNow=dateStart;
    dateStart.replace(8,9,"01");
    cout<<"Balance for period: "<<dateStart<<" - "<<dateNow<<endl;
    getBalance(dateHandler.getDays(dateStart),dateHandler.getDays(dateNow));
}

void TransactionManager::getBalanceLastMonth()
{
    string dateNow=dateHandler.getCurrentDate();
    string dateBeginning,dateEnd;
    int year=stoi(dateNow.substr(0,4));
    int month=stoi(dateNow.substr(5,6));
    int nYear,nMonth;
    if (month==1){
        nYear=year-1;
        nMonth=12;
    }
    else {
        nYear=year;
        nMonth=month-1;
    }
    if (nMonth<10){
        dateBeginning=to_string(nYear)+"-0"+to_string(nMonth)+"-"+"01";
        dateEnd=to_string(nYear)+"-0"+to_string(nMonth)+"-"+to_string(dateHandler.getNumberOfdays(nMonth,nYear));
    }

    else {
        dateBeginning=to_string(nYear)+"-"+to_string(nMonth)+"-"+"01";
        dateEnd=to_string(nYear)+"0"+to_string(nMonth)+"-"+to_string(dateHandler.getNumberOfdays(nMonth,nYear));
    }
    cout<<"Balance for period: "<<dateBeginning<<" - "<<dateEnd<<endl;
    getBalance(dateHandler.getDays(dateBeginning),dateHandler.getDays(dateEnd));
}
void TransactionManager::getBalanceCustom()
{
    string dateStart,dateEnd;
    int daysBegin,daysEnd;
    do{
    cout<<"Enter Start Date in format 'yyyy-mm-dd': ";
    cin>>dateStart;
    daysBegin=dateHandler.getDays(dateStart);
    }while(dateHandler.checkDate(dateStart)!=1);

    do{
    cout<<"Enter End Date in format 'yyyy-mm-dd': ";
    cin>>dateEnd;
    daysEnd=dateHandler.getDays(dateEnd);
    }while(dateHandler.checkDate(dateEnd)!=1);
    cout<<"Balance for period: "<<dateStart<<" - "<<dateEnd<<endl;
    getBalance(daysBegin,daysEnd);
    cin.get();
}






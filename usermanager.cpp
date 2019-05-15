#include "usermanager.h"

UserManager::UserManager(string fileWithUsers):usersFile(fileWithUsers)
{
    users=usersFile.readUsersFromFile();
}
vector<User> UserManager::getUsers()
{
    return users;
}

void UserManager::userRegistration()
{
    User user;
    cout<<"Rejestracja Uzytkownika, podaj dane:"<<endl;
    int newId=users.size();
    user.setId(newId);
    user.setName();
    user.setSurname();
    user.setLogin();
    user.setPassword();
    users.push_back(user);

    usersFile.saveUsersToFile(users);
}

void UserManager::userLogin(){
    string login = "", pass = "";

    cout << endl << "Your login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attempts = 3; attempts > 0; attempts--)
            {
                cout << "Enter password. : Attempts left" << attempts << ": ";
                cin >> pass;

                if (itr -> getPassword() == pass)
                {
                    cout << endl << "Succesfull login" << endl << endl;
                    loggedUserId= itr -> getId();
                    break;

                }
            }
            cout << "Wrong password entered 3 times." << endl;
        }
        itr++;
    }
    cout << "No such user exists." << endl << endl;
    system("pause");
}





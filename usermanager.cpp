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
    cout<<"User registration, enter your data:"<<endl;
    int newId=users.size()+1;
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
                cout << "Enter password. : Attempts left " << attempts << ": ";
                cin >> pass;

                if (itr -> getPassword() == pass)
                {
                    cout << endl << "Succesful login" << endl << endl;
                    loggedUserId= itr -> getId();
                    break;

                }
            }
            cout << "Wrong password entered 3 times." << endl;
        break;
        }
        itr++;
        //cout << "No such user exists." << endl << endl;
    }
//cout << "No such user exists." << endl << endl;
}
int UserManager::getUserLogin()
{
    return loggedUserId;
}

void UserManager::userLogout()
{
    cout<<"You are logged out"<<endl;
    loggedUserId=0;

}

void UserManager::changePassword()
{
    if(loggedUserId==0){
        cout<<"Please log in to change your password"<<endl;
        userLogin();
    }
    string newPassword = "";
    cout << "Type new password: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr->getId() == loggedUserId)
        {
            itr -> setPassword(newPassword);
            cout << "Password successfully changed." << endl << endl;
        }
    }

}
bool UserManager::isLogged()
{
    if(loggedUserId!=0){
        return true;
    }
    else {
        return false;
    }
}


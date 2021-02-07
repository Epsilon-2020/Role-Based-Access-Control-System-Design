// RoleBasedAccessControl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Operations.h"
#include "Role.h"
#include "User.h"
#include "Info.h"
#include "UserDatabase.h"
#include <map>
#include <unordered_set>
#include <algorithm>

#include <crtdbg.h>
using namespace std;

//Function Declarations
void createAdmin(string name);
void makeOperationsList(map<int, string> &operationsList);
void displayOperationsList(User* currentUser);
void changeUser(int userID);

//Global Variables
map<int, string> operationsList;
vector<User> userDatabase;

int main()
{
  cout << "Welcome in  BlueStacks \n\n\n";
  cout << "Create Admin... \n";
  cout << "Please enter your name \n";

  string adminName;
  cin >> adminName;
  createAdmin(adminName);

  cout << "Logged in as Admin \n\n";

  //fill the operations list to display
  makeOperationsList(operationsList);

  start:
  //display the list of operations current user can access - 
  UserDatabase *pUserdatabase = UserDatabase::getUserDataBase();
  displayOperationsList(pUserdatabase->currentLoggedInUser);

  cout << "To log out, enter 404" << endl;
  int response=0;

  while (1)
  {
    cin >> response;
    if (response >= 0 && response <= 7)
    {
      Operations op;
      op.CallFunction(response, pUserdatabase->currentLoggedInUser->getInfo());
    }
    else if (response == 404) 
    {
      int loginID;
      cout << "Logging out...\n" << endl;
      cout << "Enter your userID  to login: \n";
      cin >> loginID;
      changeUser(loginID);
      goto start;
    }
    else 
    {
      cout << "Invalid Response entered, please check !!! \n";
      break;
    }
    displayOperationsList(pUserdatabase->currentLoggedInUser);
    cout << "To log out, enter 404" << endl;
  }
  if (pUserdatabase)
  {

    delete pUserdatabase;
    pUserdatabase = nullptr;
  }
  return 0;
  
}

void createAdmin(string name)
{
  vector<Role> roles;
  Role role;
  role.setRoleID(0);
  roles.push_back(role);

  Info *pinfor = new Info(name, 0, roles);
  //User admin(pinfor);
  UserDatabase *pUserdatabase = UserDatabase::getUserDataBase();
  User *pUser = new User(pinfor);
  pUserdatabase->addUser(pUser);
  pUserdatabase->currentLoggedInUser = pUser;
}

void makeOperationsList(map<int, string> &operationsList)
{
  operationsList.insert(pair<int, string>(CreateUser, "To create new user, enter 0"));
  operationsList.insert(pair<int, string>(DeleteUser, "To delete an existing user, enter 1"));
  operationsList.insert(pair<int, string>(AssignRoles, "To assign a role to an existing user, enter 2"));
  operationsList.insert(pair<int, string>(CheckRoles, "To check roles of an existing user, enter 3"));
  operationsList.insert(pair<int, string>(RemoveRole, "To remove a particular role of an existing user, enter 4"));
  operationsList.insert(pair<int, string>(ReadFile, "To Read File, enter 5"));
  operationsList.insert(pair<int, string>(WriteFile, "To Write File, enter 6"));
  operationsList.insert(pair<int, string>(Verify, "To verify a file, enter 7"));
}

void displayOperationsList(User* puser) 
{
  set<string> displayList;
  vector<Role> roles = puser->getAllRoles();
  for (auto role : roles) 
  {
    set<int> tempList;
    tempList = role.getOperationsList(role.getRoleID());
    for (auto entry : tempList) 
    {
      string str = operationsList[entry];
      displayList.insert(str);
    }
  }

  for (auto element : displayList) 
  {
    cout << element << endl;
  }
}

void changeUser(int userID) 
{
  UserDatabase *pUserdatabase = UserDatabase::getUserDataBase();
  pUserdatabase->logIN(userID);
}
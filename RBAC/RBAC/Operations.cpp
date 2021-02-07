#include "Operations.h"
#include "UserDatabase.h"


Operations::Operations()
{

}


Operations::~Operations()
{
}

void Operations::CallFunction(int oper,Info *UserInfo)
{
  switch (oper)
  {
  case OperationName::CreateUser:
  {
    CreateUser(UserInfo);
    break;
  }
  case OperationName::DeleteUser:
  {
    DeleteUser(UserInfo);
    break;
  }
  case OperationName::AssignRoles:
  {
    AssignRoles(UserInfo);
    break;
  }
  case OperationName::CheckRoles:
  {
    CheckRoles(UserInfo);
    break;
  }
  case OperationName::RemoveRole:
  {
    RemoveRole(UserInfo);
    break;
  }
  case OperationName::ReadFile:
  {
    ReadFile(UserInfo);
    break;
  }
  case OperationName::WriteFile:
  {
    WriteFile(UserInfo);
    break;
  }
  case OperationName::Verify:
  {
    Verify(UserInfo);
    break;
  }
  default:
    break;
  }
}

void Operations::CreateUser(Info* info)
{
  string strUsernane;
  int userid;
  int roleId;

  cout << "Enter User name: ";
  cin >> strUsernane;
  cout << "Enter user id";
  cin >> userid;
  cout << "Enter role id:";
  cin >> roleId;

  Role UserRole;
  UserRole.setRoleID(roleId);

  Info *pUserInfo =new Info();
  pUserInfo->_userID = userid;
  pUserInfo->_roles.push_back(UserRole);
  pUserInfo->_userName = strUsernane;


  User *pUser =  new User(pUserInfo);
  UserDatabase *pUserdatabase = UserDatabase::getUserDataBase();
  if (pUserdatabase)
  {
    pUserdatabase->addUser(pUser);
  }
  cout << "New User created successfully \n" << endl;
}

void Operations::DeleteUser(Info* UserInfo)
{
  UserDatabase *pUserdatabase = UserDatabase::getUserDataBase();
  if (pUserdatabase)
  {
    User* pUserToDelete = pUserdatabase->getUser(UserInfo);
    if (pUserToDelete)
    {
      pUserdatabase->deleteUser(pUserToDelete);
    }
  }
  cout << "User deleted successfully \n" << endl;
}

void Operations::AssignRoles(Info* UserInfo)
{
  UserDatabase *pUserdatabase = UserDatabase::getUserDataBase();
  if (pUserdatabase)
  {
    User* pUser = pUserdatabase->getUser(UserInfo);
    if (pUser)
    {
      int newRoleID = -1;
      cout << "Enter the role id : ";
      cin >> newRoleID;
      Role newRole;
      newRole.setRoleID(newRoleID);
      pUser->setRole(newRole);
    }
  }
  cout << "Role assigned successfully \n" << endl;
}

void Operations::CheckRoles(Info* UserInfo)
{
  vector<Role> listOfRoles;
  UserDatabase *pUserdatabase = UserDatabase::getUserDataBase();
  if (pUserdatabase)
  {
    User* pUser = pUserdatabase->getUser(UserInfo);
    if (pUser)
    {
      listOfRoles = pUser->getAllRoles();
    }
  }
  for (auto role : listOfRoles) {
    cout << role.getRoleName() << endl;
  }
}

void Operations::RemoveRole(Info* UserInfo)
{
  UserDatabase *pUserdatabase = UserDatabase::getUserDataBase();
  if (pUserdatabase)
  {
    User* pUser = pUserdatabase->getUser(UserInfo);
    if (pUser)
    {
      int removeThisRoleID = -1;
      cout << "Enter the role id : ";
      cin >> removeThisRoleID;
      pUser->removeRole(removeThisRoleID);
    }
  }
  cout << "Role removed successfully \n" << endl;
}

void Operations::ReadFile(Info* UserInfo)
{
  cout << "File reading done \n" << endl;
}

void Operations::WriteFile(Info* UserInfo)
{
  cout << "File writing done \n" << endl;
}

void Operations::Verify(Info* UserInfo)
{
  cout << "File verfication done \n" << endl;
}


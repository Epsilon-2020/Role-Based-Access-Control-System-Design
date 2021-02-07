#include "Info.h"
#include "UserDatabase.h"
#include <algorithm>


UserDatabase::UserDatabase()
{
  m_pUserDatabase = nullptr;
}


UserDatabase::~UserDatabase()
{
  for (auto it =userDataBase.begin(); it!=userDataBase.end(); it++ )
  {
    int idx = distance(userDataBase.begin(), it);
    User* pUserToDelete = userDataBase[idx];
    if (pUserToDelete)
    {
      delete pUserToDelete;
      pUserToDelete = nullptr;
    }
  }
}

UserDatabase * UserDatabase::getUserDataBase()
{
  if (m_pUserDatabase== nullptr)
  {
    m_pUserDatabase = new UserDatabase();
  }
  return m_pUserDatabase;
}

void UserDatabase::logIN(int userID)
{
  for (auto user : userDataBase) 
  {
    if (user->getUserID() == userID) 
    {
      cout << "logged in as " << user->getUserName() << endl;
      currentLoggedInUser = user;
    }
  }
}

void UserDatabase::addUser( User * User)
{
  userDataBase.push_back(User);
}

void UserDatabase::deleteUser( User * pUser)
{
  auto it = find(userDataBase.begin(), userDataBase.end(), pUser);
  if (it != userDataBase.end())
  {
    userDataBase.erase(it);
    int idx = distance(userDataBase.begin(),it);
    User* pUserToDelete = userDataBase[idx];
    delete pUserToDelete;
    pUserToDelete = nullptr;
  }
}
User * UserDatabase::getUser(Info * pUserInfo)
{
  User* pUser = nullptr;
  for (auto user : userDataBase)
  {
    if (pUserInfo->_userID == user->getUserID())
    {
      pUser = user;
      break;
    }
  }
  return pUser;
}
UserDatabase * UserDatabase::m_pUserDatabase = nullptr;

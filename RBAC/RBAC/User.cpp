#include "User.h"
#include "Role.h"


User::User()
{
}
User::User(Info* ipinfo)
{
  m_pinfo = ipinfo;
}
User::~User()
{
  if (m_pinfo)
  {
    delete m_pinfo;
    m_pinfo = nullptr;
  }

}

Info *User::getInfo() {

  return m_pinfo;
}

string User::getUserName()
{
  return m_pinfo->_userName;
}

void User::setUserName(string name)
{
  m_pinfo->_userName = name;
}

int User::getUserID()
{
  return m_pinfo->_userID;
}

void User::setUserID(int ID)
{
  m_pinfo->_userID = ID;
}

vector<Role> User::getAllRoles()
{
  return m_pinfo->_roles;
}

void User::setRole(Role myRole)
{
  m_pinfo->_roles.push_back(myRole);
}

void User::removeRole(int roleID)
{
  int index = 0;
  for (auto role : m_pinfo->_roles) 
  {
    if (role.getRoleID() == roleID) 
    {
      m_pinfo->_roles.erase(m_pinfo->_roles.begin()+index);
    }
    index++;
  }
}

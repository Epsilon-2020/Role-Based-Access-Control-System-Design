#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include "Info.h"

#include "Role.h"
using namespace std;

class Role;
class Info;

class User
{
private:

  Info * m_pinfo;

public:
  User();
  User(Info* info);
  ~User();

  Info * getInfo();

  string getUserName();
  void setUserName(string name);

  int getUserID();
  void setUserID(int ID);
  vector<Role> getAllRoles();
  void setRole(Role myRole);
  void removeRole(int roleID);
};


#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>


#include "Operations.h"
using namespace std;

class Operations;

class Role
{


public:
  Role();
  ~Role();

  string getRoleName();
  void setRoleName(string name);
  int getRoleID();
  void setRoleID(int roleID);

  Operations* getOperation();

  set<int> getOperationsList(int roleID);

private:
  string _roleName;
  int _roleID;
  Operations* m_operations;
};


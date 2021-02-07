#include "Role.h"

Role::Role()
{
}

Role::~Role()
{
}

string Role::getRoleName()
{
  return _roleName;
}

void Role::setRoleName(string name)
{
  _roleName = name;
}

int Role::getRoleID()
{
  return _roleID;
}

void Role::setRoleID(int roleID)
{
  _roleID = roleID;
  if (roleID == 0) {
    setRoleName("Admin");
  }
  else if (roleID == 1) {
    setRoleName("Developer");
  }
  else if (roleID == 2) {
    setRoleName("Tester");
  }
}

Operations* Role::getOperation()
{
  Operations * pOperation = new Operations();
  return pOperation;
}

set<int> Role::getOperationsList(int roleID)
{
  set<int> operationsList;

  switch (roleID)
  {
  case 0:
  {
    operationsList.insert(CreateUser);
    operationsList.insert(DeleteUser);
    operationsList.insert(AssignRoles);
    operationsList.insert(CheckRoles);
    operationsList.insert(RemoveRole);
    operationsList.insert(ReadFile);
    operationsList.insert(WriteFile);
    operationsList.insert(Verify);
    break;

  }
  case 1:
  {
    operationsList.insert(ReadFile);
    operationsList.insert(WriteFile);
    break;
  }
  case 2:
  {
    operationsList.insert(ReadFile);
    operationsList.insert(Verify);
  }
  default:
  {
    break;
  }
  }
  return operationsList;
}



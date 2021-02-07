#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Role.h"
#include <map>
#include "Info.h"
using namespace std;
class User;
class Role;
class Info;

enum  OperationName
{
  CreateUser,
  DeleteUser,
  AssignRoles,
  CheckRoles,
  RemoveRole,
  ReadFile,
  WriteFile,
  Verify
};

class Operations
{
public:
  Operations();
  ~Operations();

  void CallFunction(int oper, Info* userInfo);
  void CreateUser(Info* userInfo);
  void DeleteUser(Info* userInfo);
  void AssignRoles(Info* userInfo);
  void CheckRoles(Info* userInfo);
  void RemoveRole(Info* userInfo);
  void ReadFile(Info* userInfo);
  void WriteFile(Info* userInfo);
  void Verify(Info* userInfo);


private:
  
};


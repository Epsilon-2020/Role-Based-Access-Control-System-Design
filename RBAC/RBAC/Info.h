#pragma once
#include <iostream>
#include <string.h>
#include <vector>

#include "Role.h"
using namespace std;

class Role;
class Info
{
public:
  Info();
  Info(string username, int userID, vector<Role> roles);
  ~Info();


  string _userName;
  int _userID;
  vector<Role> _roles;
};


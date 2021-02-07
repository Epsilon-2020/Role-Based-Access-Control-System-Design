#include "Info.h"



Info::Info()
{
}

Info::Info(string username, int userID, vector<Role> roles)
{
  _userName = username;
  _userID = userID;
  _roles = roles;
}


Info::~Info()
{
}

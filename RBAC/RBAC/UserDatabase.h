#pragma once
#include <vector>
using namespace std;
class User;
class Info;
class UserDatabase
{
private:
  UserDatabase();
  static UserDatabase *m_pUserDatabase;
  vector<User*> userDataBase;
public:
  ~UserDatabase();

  static UserDatabase* getUserDataBase();
  void logIN(int userID);
  void addUser( User * User);
  void deleteUser(User * User);
  User* currentLoggedInUser;
  User* getUser(Info * pUser);
};


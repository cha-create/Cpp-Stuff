#include <iostream>
#include <string>
//TODO: Get the login screen working
using namespace std;
std::string userOpt = "";
std::string menuScreen =
"                -------------------------"
"                |         MENU          |"
"                |                       |"
"                | [L]ogin...            |"
"                |                       |"
"                | [R]egistration...     |"  
"                |                       |"
"                | [Q]uit...             |"
"                |                       |"
"                -------------------------";

class User {
  private:
    std::string password = "";
  public:
    std::string login = "";
    void setInfo() {
      cout << "Please Enter Your Desired Password: ";
      cin >> password;
      cout << "Please Enter Your Desired Login: ";
      cin >> login;
      cout << "Your Password is: " << password << endl;
      cout << "Your Login is: " << login << endl;

  }

};


void loginScreen() {
  User us1;
  us1.setInfo();
  return;
}


void getUserOpt() {
  userOpt = "";
  cout << userOpt;
  cin >> userOpt;
  
}


int main() {
  cout << menuScreen << endl;
  cout << "Please Select an Option: ";
  getUserOpt();
  if (userOpt.find("L")) {
    loginScreen();
  }
  else if (!userOpt.find("L")) {
  cout << "Invalid Entry" << endl;
}

  return 0;

};

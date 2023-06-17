#include <iostream>
#include <string>
//TODO: Get the user database and the login screen working
using namespace std;
std::string userOpt = "";
std::string menuScreen =
"                -------------------------\n"
"                |         MENU          |\n"
"                |                       |\n"
"                | [L]ogin...            |\n"
"                |                       |\n"
"                | [R]egistration...     |\n"  
"                |                       |\n"
"                | [Q]uit...             |\n"
"                |                       |\n"
"                -------------------------\n";

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
  for(int i = 0; i < 100; i++) {
    cout << menuScreen << endl;
    cout << "Please Select an Option: ";
    getUserOpt();
    if (userOpt.find("L") != string::npos) {
      loginScreen();
    }
    else if (userOpt.find("Q") != string::npos) {
      return 0;
    }
    else if (userOpt.find("L") == string::npos) {
    cout << "Invalid Entry" << endl;
    }
  }                                                

  return 0;

};

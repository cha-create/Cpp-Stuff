#include <iostream>
#include <string>
//TODO: fix login screen not logging out  
using namespace std;
bool isLoggedIn = false;
bool isRunning = true;
bool hasRegistered = false;
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
std::string loggedInScreen = 
"                -------------------------\n"
"                |       LOGGED IN       |\n"
"                |                       |\n"
"                |     [L]og out...      |\n"
"                |                       |\n"
"                |     [Q]uit...         |\n"
"                |                       |\n"
"                -------------------------\n";


class User {
  private:
    std::string password;
  public:
    std::string login;
    bool checkInfo(string log, string pass) {
      if (log.find(login) != string::npos && pass.find(password) != string::npos) {
        return true;
      }
      else {
        return false;
      }
    }


    void setInfo() {
      cout << "Please Enter Your Desired Login: ";
      cin >> login;
      cout << "Please Enter Your Desired Password: ";
      cin >> password;
      cout << "Your Login is: " << login << endl;
      cout << "Your Password is: " << password << endl;
    } 
    
    void dumpInfo() {
      cout << "Login: " << login << endl;
      cout << "Password: " << password << endl;
    }

};


void loginScreen(User& us1){
  std::string pass = "";
  std::string log = "";
  cout << "Please enter your login: ";
  cin >> log;
  cout << "Please enter your password: ";
  cin >> pass;  
  if (us1.checkInfo(log, pass)) {
    isLoggedIn = true;
    return;
  }
  else {
    cout << "Invalid Entry" << endl;
    return;
  }
}


void getUserOpt() {
  userOpt = "";
  cin >> userOpt;
  
}



void registrationScreen(User& us1) {
  us1.setInfo();
  hasRegistered = true;
  return;

}


int main() {
  User us1;
  while(isRunning) {
    if (isLoggedIn) {
      cout << loggedInScreen << endl;
      cout << "Please Select an Option: ";
      getUserOpt();
      if (userOpt.find("Q") != string::npos) {
        isRunning = false;      
      }
      else if (userOpt.find("L") != string::npos) {
        isLoggedIn = false;
      }
    }
    else {
      cout << menuScreen << endl;
      cout << "Please Select an Option: ";
      getUserOpt();
      if (userOpt.find("L") != string::npos && hasRegistered) {
        loginScreen(us1);
      }
      if (userOpt.find("L") != string::npos && !hasRegistered) {
        cout << "Please register first!\n";
      }
      else if (userOpt.find("Q") != string::npos) {
        isRunning = false;
      }
      else if (userOpt.find("R") != string::npos) {
        registrationScreen(us1);
      }
    }   
  }                                                

  return 0;

};

#include <iostream>
#include <string>
//TODO: fix login 
using namespace std;
bool isLoggedIn = false;
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
    bool checkInfo(std::string log, std::string pass) {
      if (log.find(User::login) != string::npos && pass.find(User::password) != string::npos) {
        cout << User::login;
        cout << log << endl;
        cout << pass;
        cout << User::password << endl;
        return true;
      }
      else {
        return false;
      }
    }


    void setInfo() {
      cout << "Please Enter Your Desired Password: ";
      cin >> User::password;
      cout << "Please Enter Your Desired Login: ";
      cin >> User::login;
      cout << "Your Password is: " << password << endl;
      cout << "Your Login is: " << login << endl;
    } 


};


void loginScreen(User us1){
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
  cout << userOpt;
  cin >> userOpt;
  
}



void registrationScreen(User us1) {
  us1.setInfo();
  return;

}


int main() {
  User us1;
  for(int i = 0; i < 100; i++) {
    if (isLoggedIn) {
      cout << loggedInScreen << endl;
      cout << "Please Select an Option: ";
      getUserOpt();
      if (userOpt.find("Q") != string::npos) {
        break;      
      }
      else if (userOpt.find("L")) {
        isLoggedIn = false;
        break;
      }
    }

    cout << menuScreen << endl;
    cout << "Please Select an Option: ";
    getUserOpt();
    if (userOpt.find("L") != string::npos) {
      loginScreen(us1);
    }
    else if (userOpt.find("Q") != string::npos) {
      return 0;
    }
    else if (userOpt.find("R") != string::npos) {
      registrationScreen(us1);
    }
    else if (userOpt.find("L") == string::npos) {
    cout << "Invalid Entry" << endl;
    }
  }                                                

  return 0;

};

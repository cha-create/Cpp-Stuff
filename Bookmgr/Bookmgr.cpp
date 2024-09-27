#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;
bool isRunning = true;
// Finished! If I ever come back to this project, I'd probably want to add these things:
//Writing to a .txt file to save books across program executions
//Error checking... everywhere
//Code commenting for readability
string letters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
string userOpt = "";
string adminPass = "charley18";
//Start Screens
string startScreen = 
"|-------------------|\n"
"|    BookMgr V0.1   |\n"
"|                   |\n"
"|   [R]ead(user)    |\n"
"|   [W]rite(admin)  |\n"
"|   [Q]uit          |\n"
"|                   |\n"
"|-------------------|\n";

string writeScreen = 
"|-------------------|\n"
"|       Admin       |\n"
"|                   |\n"
"|  [A]dd Book       |\n"
"|  [E]dit Book ID   |\n"
"|  [Q]uit To Main   |\n"
"|                   |\n"
"|-------------------|\n";

//basic function to wipe userOpt buffer then write to it
void getUserOpt() {
	userOpt = "";
	cin >> userOpt;
}
//defining book struct
struct book {
	string name;
	int amount;
	int id;
	void printInfo() {
		int spaceLength;
		spaceLength = 30 - name.length();
		cout << name;
		for (int i = 0; i < spaceLength; i++) {
			cout << " ";
		}
		cout<<id<<endl; 
	}
  void print3Info() {
    int spaceLength;
    spaceLength = 20 - name.length();
    cout << name;
    for (int i = 0; i < spaceLength; i++) {
      cout << " ";  
    }
    cout<< "Identifier: " << id;
    spaceLength = 20 - sizeof(amount);
    for (int i  = 0; i < spaceLength; i++) {
      cout << " ";
    }
    cout<<"Quantity: " << amount << endl;

  }
};
std::list<book> bookList;
//This Function Theorettically should work, but I dont have a debugger rn so idk why it doesn't
bool findletters(string instring) {
	if(instring.find("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") != string::npos) {
		return true;
	}
	return false;
} 



int sync() {
  ifstream f("doc.json");
  json input = json::parse(f);
  int c = 0;
  for (auto i: input) {
    c++;
  }
  if(input.is_array()) {
    for (int i = 0; i < c; i++) {    
      string name = input[i]["name"];
      int id = input[i]["id"];
      int amount = input[i]["amount"];
      book newBook = {name, id, amount};
      bookList.push_back(newBook);
      cout << id << endl;
    }  
  }
    return 0;  
}
  





//returns a pointer to a book in the array passed in 
book* findBook(int id) {
	for (auto& book : bookList) {
		if(book.id == id) {
			return &book;
		}
	}
	return nullptr;
}

//the printinfo function the the book struct is used here to print all off the book stats exept for id. 
//If the user would like to know more information, the print3Info function 
//prints out all 3 stats on the requested book. 
void readScreen() {
	for(auto& book : bookList) {
		book.printInfo();
	}
	cout << "Please Select a Book From This List by The Book ID: ";
	getUserOpt();
  if (findletters(userOpt)) { // doesn't work 
		cout << "Invalid Entry. Please make sure your id is only numbers." << endl;
		return;
	}
	book* selectedBook = findBook(stoi(userOpt));
	cout << "Book: ";
  selectedBook->print3Info();
}

void welcomeScreen() {
  cout << "\033[32m\n" << startScreen << "\033[0m\n" << endl;
	cout << "Welcome. Please Select an Option: ";
	getUserOpt();
	return;
}

int generateBookID() {
	int id;
	srand(static_cast<unsigned int>(time(nullptr)));
	for(int i = 0; i < 4; i++) {
		id = id * 10 + (rand() % 10);
	}
	return id;
}

//asks the user for book stats then concatenates them into a new entry into the book struct.
void addBook() {
	string bNameIn;
	int  bQuanIn;
	int bID;
	cout << "Please Enter Book Name: ";
	cin.ignore(1);
	getline(cin,  bNameIn);
	cout << "Please Enter Book Quantity: ";
	cin >> bQuanIn;
	cout << "Generating Book ID";
	bID = generateBookID();
	cout << endl;
	cout << "Book ID: " << bID << "\n";
	//int quantity = stoi(bQuanIn);
	book newBook{bNameIn, bQuanIn, bID};
	bookList.push_back(newBook);
	cout << "New Book Added With Name: " << bNameIn << ", A Quantity of: " << bQuanIn << ", and an ID of: " << bID << ".\n";
}
//asks the user to edit a specific book id or generate a new one using the generateBookID functions above.
void editBookID() {
    string inID;
    string inBook;    
    cout << "Please Select a Book From This List by Book ID: " << endl;
    for (auto& book : bookList) {
        book.printInfo();
    }
    cin.ignore(1);
    cout << ":";
    getline(cin, inBook);
    book* bookptr = findBook(stoi(inBook));
    cout << "Please enter a new book ID or type 'G' to regenerate one: ";
    cin >> inID;
//    if (findString(inID).empty()) {
//        cout << "Invalid Entry";
//    }
    cout << "INID: " << inID << endl;

    if (inID.find("G") != string::npos || inID.find("g") != string::npos) {
        bookptr->id = generateBookID();
    }
 	else{
        bookptr->id = stoi(inID);
    }
   	cout << "Book ID changed to: " << bookptr->id << endl;
}


//asks the user for credentials and then shows them the edit/write screen.
void writeMenu() {
	string passIn;
	cout << "This task requires administrator access. Please enter the administrator password:" << endl;
	cin >> passIn;
	if (passIn == adminPass) {
		cout << "\033[32m\n" << writeScreen << "\033[0m\n";
		cout << "Please Select An Option: ";
		getUserOpt();
		if (userOpt.find("A") != string::npos) {
			addBook();
		}
		else if (userOpt.find("E") != string::npos) {
			editBookID();
		}
    else if (userOpt.find("Q") != string::npos) {
    userOpt = "";
      return;
    }
  } 

	else if (passIn != adminPass) {
		cout << "The password you have provided is incorrect." << endl;
		return;
	}
}
	
//the main function that calls other functions depending on the screen shown.
int main() {
	book book1 = {"Elden Ring", 52, 69}; // Example Books
	bookList.push_back(book1);
	book book2 = {"Elden Roadffdsa", 523, 6379};
	bookList.push_back(book2);
	book book3 = {"Elden Roadffdsadfafasfads", 523, 6679};
	bookList.push_back(book3);
	book book4 = {"ask", 43, 659};
	bookList.push_back(book4);
  sync();
	while(true) {
		if (isRunning) {
			welcomeScreen();
			if (userOpt.find("R") != string::npos || userOpt.find("r") != string::npos ) {
				readScreen();
			}
			else if(userOpt.find("W") != string::npos || userOpt.find("w") != string::npos) {
				writeMenu();
			}
			if (userOpt.find("Q") != string::npos || userOpt.find("q") != string::npos) {
				return 0;
			}
			else {
				cout << "Please either Q, W, or R." << endl;
			}
		}	
	}
return 0;
}

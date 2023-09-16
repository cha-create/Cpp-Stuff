#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
//TODO:Add book id change function
using namespace std;
bool isRunning = true;
string userOpt = "";
string adminPass = "charley18";
string startScreen = 
"---------------------\n"
"|    BookMgr V0.1   |\n"
"|                   |\n"
"|   [R]ead(user)    |\n"
"|   [W]rite(admin)  |\n"
"|                   |\n"
"---------------------\n";

string writeScreen = 
"---------------------\n"
"|       Admin       |\n"
"|                   |\n"
"|  [A]dd Book       |\n"
"|  [E]dit Book ID   |\n"
"|                   |\n"
"--------------------|\n";

void getUserOpt() {
	userOpt = "";
	cin >> userOpt;
}

struct book {
	string name;
	int amount;
	int id;
	void printInfo() {
		cout<<name<< "             " <<id<<endl; //Fix output alignment varying based on book name length
	}
};
std::list<book> bookList;

book* findBook(int id) {
	for (auto& book : bookList) {
		if(book.id == id) {
			return &book;
		}
	}
	return nullptr;
}

void readScreen() {
	for(auto& book : bookList) {
		book.printInfo();
	}
	cout << "Please Select a Book From This List by The Book ID: ";
	getUserOpt();
	book* selectedBook = findBook(stoi(userOpt));
	selectedBook->printInfo();
}
 
void welcomeScreen() {
	cout << startScreen << endl;
		cout << "Welcome. Please Select an Option: ";
		getUserOpt();
		return;
}

int generateBookID() {
	int id;
	srand(static_cast<unsigned int>(time(nullptr)));
	for(int i = 0; i < 8; i++) {
		id = id * 10 + (rand() % 10);
	}
	return id;
}


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


void writeMenu() {
	string passIn;
	cout << "This task requires administrator access. Please enter the administrator password:" << endl;
	cin >> passIn;
	if (passIn == adminPass) {
		cout << writeScreen;
		cout << "Please Select An Option: ";
		getUserOpt();
		if (userOpt.find("A") != string::npos) {
			addBook();
		}
	} 

	else if (passIn != adminPass) {
		cout << "The password you have provided is incorrect." << endl;
		return;
	}
}

int main() {
	while(true) {
		if (isRunning) {
			welcomeScreen();
			if (userOpt.find("R") != string::npos) {
				readScreen();
			}
			else if(userOpt.find("W") != string::npos) {
				writeMenu();
			}
		}	
	}
return 0;
}

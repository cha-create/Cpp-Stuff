#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;
bool isRunning = true;
// Finished! If I ever come back to this project, I'd probably want to add these things:
//Writing to a .txt file to save books across program executions
//Error checking... everywhere
//Code commenting for readability
//string letters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
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
		int spaceLength;
		spaceLength = 30 - name.length();
		cout << name;
		for (int i = 0; i < spaceLength; i++) {
			cout << " ";
		}
		cout<<id<<endl; //Fix output alignment varying based on book name length
	}
};
std::list<book> bookList;

//string findString(const string& inString) {
//	for (char charElement : inString) {
//		string stringElement(1, charElement);
//		if (stringElement.find(letters)) {
//			return stringElement;
//		}
//	}
//	return nullptr;
//} 

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
	for(int i = 0; i < 4; i++) {
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
		else if (userOpt.find("E") != string::npos) {
			editBookID();
		}
	} 

	else if (passIn != adminPass) {
		cout << "The password you have provided is incorrect." << endl;
		return;
	}
}
	
int main() {
	book book1 = {"Elden Ring", 52, 69}; // Example Books
	bookList.push_back(book1);
	book book2 = {"Elden Roadffdsa", 523, 6679};
	bookList.push_back(book2);
	book book3 = {"Elden Roadffdsadfafasfads", 523, 6679};
	bookList.push_back(book3);
	book book4 = {"ask", 43, 659};
	bookList.push_back(book4);
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

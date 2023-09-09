#include <iostream>
#include <string>
#include <list>
//TODO: Add write functinality and allow code to return to startScreen
using namespace std;
bool isRunning = true;
std::string userOpt = "";
std::string startScreen = 
"---------------------\n"
"|    BookMgr V0.1   |\n"
"|                   |\n"
"|   [R]ead(user)    |\n"
"|   [W]rite(admin)  |\n"
"|                   |\n"
"---------------------\n";

void getUserOpt() {
	userOpt = "";
	cin >> userOpt;
}

struct book {
	string name;
	int amount;
	int id;
	void printInfo() {
		cout<<name<< "             " <<id<<endl;
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

int main() {
	book book1{"Balls", 1,1239374};
	bookList.push_back(book1);
	book book2{"alls", 5,127689374};
	bookList.push_back(book2);
	book book3{"Balfs", 69,1239};
	bookList.push_back(book3);
	if (isRunning) {
		cout << startScreen << endl;
		cout << "Welcome. Please Select an Option: ";
		getUserOpt();
		if (userOpt.find("R") != string::npos) {
			for(auto& book : bookList) {
				book.printInfo();
		}
		cout << "Please Select a Book From This List by The Book ID: ";
		getUserOpt();
		book* selectedBook = findBook(stoi(userOpt));
		selectedBook->printInfo();

	}
	return 0;
}
}

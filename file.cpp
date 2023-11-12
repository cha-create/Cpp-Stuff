#include <iostream>
#include <fstream>

using namespace std;

int main() {
  fstream myfile("File.txt");
  cout << "file created." << endl;
  myfile << "its a file. yay" << endl;
  myfile.close();
}

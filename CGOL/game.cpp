#include <iostream>
#include <stdlib.h>
#include <chrono> // For wait function
#include <thread>
using namespace std;
int simCount = 0;
int mainArr[8][8] = {
  {1, 0, 1, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 1, 0, 1, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 }
};

void draw() {
  for(int i = 0; i < 8; i++) {
    for(int c = 0; c < 8; c++) {
      if(c == 7) {
        cout << mainArr[i][c] << endl;
      }
      else {
        cout << mainArr[i][c];
      }
    }
  }
}


void update() {
  //main game logic
  for(int y = 0; y < 8; y++) {
    for(int x = 0; x < 8; x++) {
      if(x >= 1 && y >= 1) {
        int onCount = 0;
        int offCount = 0;
        //get row above pixel
        if(mainArr[y - 1][x - 1] == true) {
          onCount += 1;
        }
        else {
          offCount += 1;
        }
        if(mainArr[y - 1][x] == true) {
          onCount += 1;
        }
        else {
          offCount += 1;
        }
        if(mainArr[y - 1][x + 1] == true) {
          onCount += 1;
        }
        else {
          offCount += 1;
        }
        //cout << "onC: " << onCount << endl;
        //cout << "offC:" << offCount << endl;
        //cout << mainArr[y + 1][x- 1] << mainArr[y+1][x] << mainArr[y+1][x+1] << endl;
        if(onCount >= 2) {
          mainArr[x][y] = 1;
        }
      }
  }
}
}
int main() {
  while(simCount <=4) {
    update();
    this_thread::sleep_until(chrono::system_clock::now() + chrono::milliseconds(250));
    draw();
    cout << "Simulation Step: " << simCount << endl;
    simCount++;
    cout << endl;
  }
 return 0;
}

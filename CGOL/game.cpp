#include <iostream>
#include <stdlib.h>
#include <chrono> // For wait function
#include <thread>
using namespace std;
int simCount = 0;
int simLength = 0;
int mainDelay = 0;
int userOpt;

//TODO: Add user-definable grid size

int mainArr[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 1, 0, 0, 0, 0, 0  },
  {0, 0, 1, 1, 1, 0, 0, 0 },
  {0, 0, 1, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 }
};

int currentArr[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 }
};

int offsetMatrix[8][2] = {
  {-1, -1},
  {0, -1},
  {1, -1},
  {-1, 0},
  {1, 0},
  {-1, 1},
  {0, 1},
  {1, 1}
};

void promptUser() {
  cout << "Welcome to Conway's Game of Life!" << endl;
  cout << "How many simulation loops do you want?: ";
  cin >> simLength;
  cout << "How fast do you want the sim to run?(0-9; 9 is fastest): ";
  cin >> userOpt;
  mainDelay = (250 - (20 * userOpt));
  return;
}

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

void clearArray(int (&array)[8][8]) {
  for(int i = 0; i < 8; i++) {
    for(int c = 0; c < 8; c++){   // c++ in C++!
      array[i][c] = 0;
    }
  }
}

void copyArray(int (&array1)[8][8], int (&array2)[8][8]) {
  for(int i = 0; i < 8; i++) {
    for(int c = 0; c < 8; c++) {
      array2[i][c] = array1[i][c];
    } 
  }
}

int applyRulesToCell(int currentState, int numOn) {
    if (numOn < 2 || numOn > 3) {
        return 0; // Cell dies or stays dead
    }
    if (currentState == 1 && (numOn == 2 || numOn == 3)) {
        return 1; // Cell survives
    }
    if (currentState == 0 && numOn == 3) {
        return 1; // Cell becomes alive
    }
    return 0; // Default case (cell stays dead)
}
void update() {
  //main game logic
  for(int x = 0; x < 8; x++) {
    for(int y = 0; y < 8; y++) {
      if(x >= 1 && y >= 1) {
          int onCount = 0;
          int offCount = 0;
          if(x >= 1 && y >= 1) {
            for(int i = 0; i < 8; i++) {
              int checkedX = (x + offsetMatrix[i][0]);
              int checkedY = (y + offsetMatrix[i][1]);
              if(mainArr[checkedY][checkedX] == 1) {
                onCount += 1;
              }
              else {
                offCount += 1;
              }
            }
            currentArr[y][x] = applyRulesToCell(mainArr[y][x], onCount);        }
      }
  }
}
}
// Game logic runs as follows:
// Draw current mainArr
// Copy mainArr to currentArr
// Apply logic to currentArr
// Copy currentArr to mainArr
int main() { 
  promptUser();
  while(simCount <= simLength) {
    clearArray(currentArr);
    draw();
    copyArray(mainArr, currentArr);
    update();
    copyArray(currentArr, mainArr);
    this_thread::sleep_until(chrono::system_clock::now() + chrono::milliseconds(mainDelay));
    cout << "Simulation Step: " << simCount << endl;
    simCount++;
    cout << endl;
  }
 return 0;
}

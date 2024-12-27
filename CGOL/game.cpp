#include <iostream>
#include <stdlib.h>
#include <chrono> // For wait function
#include <thread>
using namespace std;
int simCount = 0;
int simLength = 15;
int mainArr[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 0, 0, 0, 0 },
  {0, 0, 0, 0, 1, 1, 0, 1 },
  {0, 0, 0, 0, 1, 0, 0, 0 },
  {0, 0, 0, 0, 0, 1, 0, 0 },
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

int applyRulesToCell(int (&array)[8][8],  int x, int y, int numOn) {
  int value = 0;
  if(numOn < 2) {
    value = 0;
  }
  else if(numOn > 3){
    value = 0;
  }
  else if(array[y][x] == 0 && numOn > 1) {
    value = 1;
  }
  array[y][x] = value;
  return value;
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
              if(currentArr[checkedY][checkedX] == 1) {
                onCount += 1;
              }
              else {
                offCount += 1;
              }
            }
          applyRulesToCell(currentArr, x, y, onCount);
        }
      }
  }
}
}
// Game logic runs as follows:
// Clear currentArr
// Draw current mainArr
// Copy mainArr to currentArr
// Apply logic to currentArr
// Copy currentArr to mainArr
int main() {
  while(simCount <= simLength) {
    clearArray(currentArr);
    draw();
    copyArray(mainArr, currentArr);
    update();
    copyArray(currentArr, mainArr);
    this_thread::sleep_until(chrono::system_clock::now() + chrono::milliseconds(250));
    cout << "Simulation Step: " << simCount << endl;
    simCount++;
    cout << endl;
  }
 return 0;
}

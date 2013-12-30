#include <iostream>

using namespace std;

char grid[10][10];

int main() {
  int r, c;
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < r; i++) {
    bool good = true;
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 'S') {
        good = false;
      }
    }

    if (good) {
      for (int j = 0; j < c; j++) {
        grid[i][j] = 'X';
      }
    }
  }

  for (int i = 0; i < c; i++) {
    bool good = true;
    for (int j = 0; j < r; j++) {
      if (grid[j][i] == 'S') {
        good = false;
      }
    }

    if (good) {
      for (int j = 0; j < r; j++) {
        grid[j][i] = 'X';
      }
    }
  }

  int count = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 'X') {
        count++;
      }
    }
  }

  cout << count << endl;
}

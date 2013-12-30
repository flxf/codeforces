#include <iostream>

using namespace std;

int grid[3][3];
int state[3][3];

void toggle(int i, int j, int k) {
  if (i < 0 || i >= 3 || j < 0 || j >= 3) {
    return;
  }
  state[i][j] = (state[i][j] + k) % 2;
}

int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      state[i][j] = 1;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      toggle(i - 1, j, grid[i][j]);
      toggle(i, j, grid[i][j]);
      toggle(i + 1, j, grid[i][j]);
      toggle(i, j - 1, grid[i][j]);
      toggle(i, j + 1, grid[i][j]);
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << state[i][j];
    }
    cout << endl;
  }
}

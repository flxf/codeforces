#include <iostream>

using namespace std;

char grid[100][100];
int n;

char get(int i, int j) {
  if (i < 0 || i == n || j < 0 || j == n) {
    return '.';
  }
  return grid[i][j];
}

bool erase(int i, int j) {
  if (get(i, j) == '#') {
    grid[i][j] = '.';
    return true;
  }
  //cout << "BAD ERASE: " << i << "," << j << endl;
  return false;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (get(i, j) == '#') {
        //cout << "FOUND: " << i << "," << j << endl;
        bool good = erase(i, j) && erase(i + 1, j) && erase(i + 2, j) && erase(i + 1, j - 1) && erase(i + 1, j + 1);

        //for (int a = 0; a < n; a++) {
          //for (int b = 0; b < n; b++) {
            //cout << grid[a][b];
          //}
          //cout << endl;
        //}


        if (!good) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }

  cout << "YES" << endl;
  return 0;
}

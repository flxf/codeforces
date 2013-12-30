#include <iostream>

using namespace std;

char grid[4][4];

bool sq(int i, int j) {
  int cnt = 0;
  if (grid[i][j] == '#') {
    cnt++;
  }
  if (grid[i+1][j] == '#') {
    cnt++;
  }
  if (grid[i][j+1] == '#') {
    cnt++;
  }
  if (grid[i+1][j+1] == '#') {
    cnt++;
  }

  int dnt = 0;
  if (grid[i][j] == '.') {
    dnt++;
  }
  if (grid[i+1][j] == '.') {
    dnt++;
  }
  if (grid[i][j+1] == '.') {
    dnt++;
  }
  if (grid[i+1][j+1] == '.') {
    dnt++;
  }

  //printf("%d,%d\n", cnt, dnt);
  return cnt >= 3 || dnt >= 3;
}

int main() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      //scanf("%c", &(grid[i][j]));
      cin >> grid[i][j];
    }
  }

  bool res = false;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      res |= sq(i, j);
    }
  }

  if (res) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

#include <iostream>

using namespace std;

char grid[1000][1000];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      grid[i][j] = '.';
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i % 2; j < n; j += 2) {
      grid[i][j] = 'C';
      cnt++;
    }
  }

  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

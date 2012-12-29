#include <iostream>

using namespace std;

int grid[1000][1000];

int main() {
  int n, m;
  cin >> n >> m;

  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    y--;

    grid[x][y] = 1;

    for (int a = -2; a <= 0; a++) {
      for (int b = -2; b <= 0; b++) {
        if (a + x >= 0 && a + x + 2 < n && b + y >= 0 && b + y + 2 < n) {
          int cnt = 0;
          for (int u = 0; u < 3; u++) {
            for (int v = 0; v < 3; v++) {
              cnt += grid[a + x + u][b + y + v];
            }
          }

          if (cnt == 9) {
            cout << i + 1 << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << -1 << endl;

  //for (int i = 0; i < n; i++) {
    //for (int j = 0; j < n; j++) {
      //cout << grid[i][j];
    //}
    //cout << endl;
  //}
}

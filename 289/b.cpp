#include <iostream>
#include <cstdlib>

using namespace std;

int grid[100][100];

int main() {
  int n, m, d;
  cin >> n >> m >> d;

  int mn = 100000;
  int mx = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      mn = min(grid[i][j], mn);
      mx = max(grid[i][j], mx);
    }
  }

  //sanity
  int mod = grid[0][0] % d;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] % d != mod) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  int targ = mn;
  int ans = 1000000000;
  while (targ <= mx) {
    int cost = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cost += abs(grid[i][j] - targ) / d;
      }
    }

    ans = min(ans, cost);
    targ += d;
  }

  cout << ans << endl;
}

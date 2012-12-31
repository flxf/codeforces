#include <iostream>

using namespace std;

#define MAX_COST 1000001
#define HASH 0
#define UNHASH 1

char grid[1000][1000];
int marked[1000];
int n, m, x, y;

int dp[1000][2][1001];

int rec(int p, int c, int l) {
  if (l > p + 1) {
    return MAX_COST;
  }

  if (dp[p][c][l] != -1) {
    return dp[p][c][l];
  }

  int imm = (c == UNHASH) ? marked[p] : n - marked[p];
  if (p == 0) {
    return imm;
  }

  if (l == 1) {
    int best = MAX_COST;
    for (int i = x; i <= y; i++) {
      best = min(best, rec(p - 1, 1 - c, i));
    }
    dp[p][c][l] = imm + best;
    return imm + best;
  } else {
    dp[p][c][l] = imm + rec(p - 1, c, l - 1);
    return dp[p][c][l];
  }
}

int main() {
  cin >> n >> m >> x >> y;

  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k <= 1000; k++) {
        dp[i][j][k] = -1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  for (int j = 0; j < m; j++) {
    marked[j] = 0;
    for (int i = 0; i < n; i++) {
      if (grid[i][j] == '#') {
        marked[j]++;
      }
    }
  }

  //for (int i = 0; i < m; i++) {
    //cout << marked[i] << " ";
  //}
  //cout << endl;

  int best = MAX_COST;
  for (int i = 0; i < 2; i++) {
    for (int j = x; j <= y; j++) {
      best = min(best, rec(m - 1, i, j));
    }
  }

  cout << best << endl;
}

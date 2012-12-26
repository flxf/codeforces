#include <iostream>
#include <cmath>

using namespace std;

int dp[101][20001];
int l;

#define SENT 20001
#define FAIL 20002

int get(int n, int d) {
  return dp[n][d + 10000];
}

void set(int n, int d, int x) {
  dp[n][d + 10000] = x;
}

int rec(int n, int d) {
  //cout << n << ":" << d << endl;
  if (n == 1) {
    if (d >= 1 && d <= l) {
      return d;
    }
    return FAIL;
  }

  if (get(n, d) != SENT) {
    return get(n, d);
  }

  for (int i = 1; i <= l; i++) {
    if (abs(i - d) <= 10000) {
      int ans = rec(n - 1, i - d);
      if (ans != FAIL) {
        set(n, d, i);
        return i;
      }
    }
  }

  set(n, d, FAIL);
  return FAIL;
}

int main() {
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 20000; j++) {
      dp[i][j] = SENT;
    }
  }

  int n, d;
  cin >> n >> d >> l;

  rec(n, d);

  int curr = d;
  if (get(n, curr) == FAIL) {
    cout << -1 << endl;
    return 0;
  }

  while (n > 1) {
    int c = get(n, curr);
    //int c = dp[n][curr];
    cout << c << " ";

    n--;
    curr = c - curr;
  }
  cout << curr << endl;
}

// DP RECURSION WITH BACKTRACKING

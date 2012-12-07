#include <iostream>

using namespace std;

int d[1000];
int s[1000];
int m, k;

int dp[1000][100000];

int rec(int p, int f) {
  if (dp[p][f] != 0) {
    return dp[p][f];
  }
  if (p == m) {
    return 0;
  }
  if (f > 1000000) {
    return 2000000000;
  }
  int of = f;
  f += s[p];
  int ans;
  if (f > d[p]) {
    ans = rec(p + 1, f - d[p]) + d[p];
  }
  ans = min(ans, rec(p, f) + k); // refuel
  dp[p][f] = ans;
  return ans;
}

int main() {
  cin >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> s[i];
  }

  cout << rec(0,0) << endl;
}

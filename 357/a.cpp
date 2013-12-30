#include <iostream>

using namespace std;

bool sums[10001];
int dp[101];

int main() {
  int m;
  cin >> m;

  dp[0] = 0;
  for (int i = 0; i < m; i++) {
    int ci;
    cin >> ci;

    dp[i + 1] = ci + dp[i];
  }

  int total = dp[m];

  int x, y;
  cin >> x >> y;

  for (int i = 0; i < m; i++) {
    if (dp[i] >= x && dp[i] <= y && total - dp[i] >= x && total - dp[i] <= y) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  cout << 0 << endl;
  return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];

int main() {
  int n, t;
  cin >> n >> t;

  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    dp[i+1] = dp[i] + a;
  }

  int mx = 0;
  for (int i = n; i >= 1; i--) {
    //cout << "search: " << dp[i] - t << endl;
    int book_index = lower_bound(dp, dp+n+1, dp[i] - t) - dp;
    //cout << book_index << ":" << dp[n - 1] - dp[book_index] << endl;
    int read = i - book_index;
    mx = max(mx, read);
  }

  cout << mx << endl;

  return 0;
}

#include <iostream>
#include <string>

using namespace std;

int dp[100000];

int main() {
  string s;
  cin >> s;

  dp[0] = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = dp[i - 1];
    }
    //cout << i << ":" << dp[i] << endl;
  }



  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    r--;
    l--;
    //cout << "(" << r << "," << l << ")(" << dp[r] << "," << dp[l] << ")" << endl;
    cout << dp[r] - dp[l] << endl;
  }
}

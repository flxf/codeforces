#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];
int dp[100000];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);

  // REVERSE THIS. SHOULD BE DISTANCE TO N OTHER THAN BUILD UP TO
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    dp[i] = (a[i] - a[i - 1]) + dp[i - 1];
    cout << dp[i] << " ";
  }
  cout << endl;

  LINEAR SEARCH ON K, where K elem of values given
  BINARY SEARCH ON N
}

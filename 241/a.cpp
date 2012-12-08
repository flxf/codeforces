#include <iostream>

using namespace std;

int d[1000];
int s[1000];
int m, k;

int dp[1000];
int ms[1000];

int main() {
  cin >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> s[i];
  }

  ms[0] = s[0];
  for (int i = 1; i < m; i++) {
    ms[i] = max(ms[i - 1], s[i]);
  }
  dp[0] = d[0];
  for (int i = 1; i < m; i++) {
    dp[i] = dp[i - 1] + d[i];
  }

  int gas = 0;
  int waits = 0;
  for (int i = 0; i < m; i++) {
    gas += s[i];
    while (gas < dp[i]) {
      waits++;
      gas += ms[i];
    }
  }

  cout << dp[m - 1] + waits * k << endl;
}

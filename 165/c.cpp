#include <iostream>

using namespace std;

int amt[1000001];
int dp[1000000];

int main() {
  int k;
  cin >> k;

  string s;
  cin >> s;

  unsigned long long sum = 0;

  dp[0] = s[0] - '0';
  amt[dp[0]]++;
  for (int i = 1; i < s.size(); i++) {
    dp[i] = (s[i] - '0') + dp[i - 1];
    amt[dp[i]]++;
  }

  for (int i = 0; i < s.size(); i++) {
    if (dp[i] - k < 0) {
      continue;
    }

    sum += amt[dp[i] - k];
    if (dp[i] - k == 0 && k != 0) {
      sum++;
    }
  }
  cout << sum << endl;
}

// SPECIAL CASE 0

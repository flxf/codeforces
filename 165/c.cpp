#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000000];
int minpos[1000001];
int maxpos[1000001];

int main() {
  int k;
  cin >> k;

  string s;
  cin >> s;

  int n = s.size();

  for (int i = 0; i <= 1000000; i++) {
    minpos[i] = -2;
    maxpos[i] = -2;
  }

  // redefine DP to not suck
  dp[0] = s[0] - '0';
  minpos[dp[0]] = 0;
  maxpos[dp[0]] = 0;

  for (int i = 1; i < n; i++) {
    dp[i] = (s[i] - '0') + dp[i - 1];
    if (minpos[dp[i]] == -2) {
      minpos[dp[i]] = i;
    }
    maxpos[dp[i]] = i;
  }

  minpos[0] = -1;
  if (maxpos[0] == -2) {
    maxpos[0] = -1;
  }

  unsigned long long sum = 0;
  for (int i = 0; i < s.size(); i++) {
    int amt = dp[i];
    int want = amt - k;
    if (want < 0) {
      continue;
    }

    int minp = minpos[want];
    int maxp;
    if (k == 0) {
      maxp = i - 1;
    } else {
      maxp = maxpos[want];
    }

    //cout << i << ":" << maxp << ":" << minp << endl;
    if (minp == -2) {
      continue;
    }

    //cout << maxp - minp + 1 << endl;
    sum += (maxp - minp + 1);
  }

  cout << sum << endl;
}

// SPECIAL CASE 0

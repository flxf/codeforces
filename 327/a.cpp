#include <iostream>
#include <cstdlib>

using namespace std;

int a[100];
int rhs[100];
int dp[100];
int n;

int range(int first, int last) {
  if (last < first) {
    return 0;
  }
  if (first == 0) {
    return dp[last];
  }
  return dp[last] - dp[first - 1];
}

int flipped(int first, int last) {
  return (last - first + 1) - range(first, last);
}

int main() {
  cin >> n;

  cin >> a[0];
  dp[0] = a[0];
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    dp[i] = dp[i - 1] + a[i];
  }

  int best = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int flip = flipped(i, j);
      best = max(best, flip + range(0, i - 1) + range(j + 1, n - 1));
    }
  }

  cout << best;
}

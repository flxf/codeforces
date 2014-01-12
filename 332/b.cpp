#include <iostream>

using namespace std;

#define ULL unsigned long long

ULL a[200000];
ULL dp[200000];
ULL maxes[200000];
ULL maxi[200000];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ULL sum = 0;
  for (int i = 0; i < k; i++) {
    sum += a[i];
  }
  dp[0] = sum;
  for (int i = k; i < n; i++) {
    sum += a[i];
    sum -= a[i - k];
    dp[i - k + 1] = sum;
  }

  maxes[n - k + 1] = dp[n - k + 1];
  maxi[n - k + 1] = n - k + 1;
  for (int i = n - k; i >= 0; i--) {
    if (dp[i] >= maxes[i + 1]) {
      maxes[i] = dp[i];
      maxi[i] = i;
    } else {
      maxes[i] = maxes[i + 1];
      maxi[i] = maxi[i + 1];
    }
  }

  ULL best = 0;
  int bestx, besty;
  for (int i = 0; i < n - 2 * k + 1; i++) {
    if (dp[i] + maxes[i + k] > best) {
      best = dp[i] + maxes[i + k];
      bestx = i;
      besty = maxi[i + k];
    }
  }
  cout << bestx + 1 << " " << besty + 1 << endl;
}

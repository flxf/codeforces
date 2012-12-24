#include <iostream>
#include <algorithm>

using namespace std;

long long a[100000];
long long sum[100000];

long long range(int x, int y) {
  if (x == 0) {
    return sum[y];
  }
  return sum[y] - sum[x - 1];
}

int main() {
  int n;
  long long k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);

  sum[0] = a[0];
  for (int i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }

  long long best = a[0];
  long long bc = 1;

  for (int i = 1; i < n; i++) {
    int lo = 0;
    int hi = i;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      long long tot = range(mid, i);
      long long aspire = (i - mid + 1) * a[i];

      if (aspire - tot <= k) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    if (i - lo + 1 > bc) {
      bc = i - lo + 1;
      best = a[i];
    }

    // lo
    //cout << a[i] << ":" << (i - lo + 1) << endl;
    //cout << a[i] << ":" << hi << ":" << lo << endl;
  }

  cout << bc << " " << best << endl;



}

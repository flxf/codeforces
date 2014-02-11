#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long

LL a[100000];
LL sums[100001];
LL lft[100001];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  reverse(a, a+n);

  sums[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    sums[i] = a[i] + sums[i + 1];
  }

  string m;
  cin >> m;

  reverse(m.begin(), m.end());

  LL best = 0;
  for (int i = 0; i < m.size(); i++) {
    if (m[i] == '1') {
      best += a[i];
    }
  }

  lft[0] = (m[0] == '1') ? a[0] : 0;
  for (int i = 1; i < m.size(); i++) {
    lft[i] = lft[i - 1];
    if (m[i] == '1') {
      lft[i] += a[i];
    }
  }

  for (int i = 0; i < m.size(); i++) {
    if (m[i] == '1') {
      LL pre = (i == 0) ? 0 : lft[i - 1];
      best = max(best, pre + sums[i + 1]);
    }
  }

  cout << best << endl;
}

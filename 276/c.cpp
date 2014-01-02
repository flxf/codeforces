#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

unsigned long long a[200000];
pair<int, char> b[400000];
long long freq[200000];

int main() {
  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;

    b[2 * i] = make_pair(l, '(');
    b[2 * i + 1] = make_pair(r + 1, ')');
  }

  sort(a, a+n);
  sort(b, b+2*q);

  int cnt = 0;
  int stacked = 0;
  for (int i = 0; i < n; i++) {
    while (cnt < 2 * q && b[cnt].first <= i) {
      if (b[cnt].second == '(') {
        stacked++;
      } else {
        stacked--;
      }
      cnt++;
    }

    freq[i] = stacked;
  }

  sort(freq, freq+n);

  unsigned long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += freq[i] * a[i];
  }
  cout << sum << endl;
}

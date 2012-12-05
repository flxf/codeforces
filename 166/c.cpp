#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];

int abs(int b) {
  if (b < 0) {
    return b * -1;
  }
  return b;
}

int main() {
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  int med = n/2;

  int p = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      if (p == -1 || abs(med - i) < abs(med - p)) {
        p = i;
      }
    }
  }

  if (p == -1) {
    cout << n << endl;
  } else {
    if (p == med) {
      cout << 0 << endl;
    } else if (p < med) {
      cout << 1 + (med - p - 1) * 2 << endl;
      //else {
        //cout << 2 * (med - p) << endl;
      //}
    } else {
      cout << 1 + (p - med - 1) * 2 << endl;
      //else {
        //cout << 2 * (p - med) << endl;
      //}
    }
  }
}

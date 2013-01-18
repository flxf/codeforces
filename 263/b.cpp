#include <iostream>
#include <algorithm>

using namespace std;

int a[50];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a+n);
  reverse(a, a+n);

  if (k > n) {
    cout << -1 << endl;
  } else {
    cout << a[k - 1] << " 0" << endl;
  }
}

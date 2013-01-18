#include <iostream>
#include <algorithm>

using namespace std;

int q[100000];
int a[100000];

int main() {
  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    cin >> q[i];
  }
  sort(q, q+m);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  reverse(a, a+n);

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int p = i % (q[0] + 2);
    if (p >= q[0]) {
    } else {
      sum += a[i];
    }
  }

  cout << sum << endl;
}

#include <iostream>
#include <algorithm>

using namespace std;

int a[100];

int main() {
  int n, d;
  cin >> n >> d;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);

  int m;
  cin >> m;

  int profit = 0;
  for (int i = 0; i < min(m, n); i++) {
    profit += a[i];
  }

  if (m > n) {
    profit -= (m - n) * d;
  }

  cout << profit << endl;
}

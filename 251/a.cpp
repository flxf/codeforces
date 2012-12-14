#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];

int main() {
  int n, d;
  cin >> n >> d;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  unsigned long long sum = 0;
  for (int i = 0; i < n - 2; i++) {
    unsigned long long range = upper_bound(a, a+n, a[i] + d) - a;
    //if (range == n) {
      range--;
    //}
    range -= i;

    if (range < 2) {
      sum += 0;
      //cout << 0 << endl;
    } else {
      sum += ((range - 1) * range) / 2;
    }
  }

  cout << sum << endl;
}

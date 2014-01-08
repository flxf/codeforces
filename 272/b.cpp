#include <iostream>
#include <algorithm>

using namespace std;

long long f(long long x) {
  if (x == 0) {
    return 0;
  }
  if (x % 2 == 0) {
    return f(x / 2);
  }
  return f(x / 2) + 1;
}

long long a[100000];
long long cnts[100];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = f(a[i]);
    cnts[a[i]]++;
  }

  long long ans = 0;
  for (int i = 0; i < 100; i++) {
    ans += (cnts[i] * (cnts[i] - 1)) / 2;
  }

  cout << ans << endl;
}

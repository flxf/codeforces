#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int a[100000];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int g = a[0];
  int mn = a[0];
  for (int i = 1; i < n; i++) {
    g = gcd(g, a[i]);
    mn = min(mn, a[i]);
  }

  if (g == mn) {
    cout << g << endl;
  } else {
    cout << -1 << endl;
  }
}

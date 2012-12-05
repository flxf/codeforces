#include <iostream>

using namespace std;

int gcd(int n, int d) {
  if (d == 0) {
    return n;
  }
  return gcd(d, n % d);
}

int main() {
  int n, m;
  cin >> n >> m;

  int a;
  cin >> a;

  int v;
  for (int i = 1; i < n + 1; i++) {
    cin >> v;
  }

  int b;
  cin >> b;
  for (int i = 1; i < m + 1; i++) {
    cin >> v;
  }

  if (n > m) {
    if (a * b > 0) {
      cout << "Infinity" << endl;
    } else {
      cout << "-Infinity" << endl;
    }
  } else if (m > n) {
    cout << "0/1" << endl;
  } else {
    int aa = a < 0 ? a * -1 : a;
    int ab = b < 0 ? b * -1 : b;
    int g = gcd(aa, ab);

    if (a * b > 0) {
      cout << aa / g << "/" << ab / g << endl;
    } else {
      cout << "-" << aa / g << "/" << ab / g << endl;
    }
  }
}

#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return 0;
  }

  int times = a / b;
  return times + gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;

  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    cout << gcd(a, b) << endl;
  }
}

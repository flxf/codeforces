#include <iostream>

using namespace std;

int mask(int n) {
  int ans = 0;
  int t = 1;
  while (n != 0) {
    int d = n % 10;
    if (d == 4 || d == 7) {
      ans += d * t;
      t *= 10;
    }
    n /= 10;
  }
  return ans;
}

int main() {
  int a, b;
  cin >> a >> b;

  for (int i = a + 1; ; i++) {
    if (mask(i) == b) {
      cout << i << endl;
      return 0;
    }
  }
}

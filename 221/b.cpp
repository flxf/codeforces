#include <iostream>

using namespace std;

bool digit[10];

bool also(int d) {
  while (d != 0) {
    if (digit[d % 10]) {
      return true;
    }
    d /= 10;
  }
  return false;
}

int main() {
  int x;
  cin >> x;
  if (x == 1) {
    cout << 1 << endl;
    return 0;
  }

  int x2 = x;
  while (x2 != 0) {
    digit[x2 % 10] = true;
    x2 /= 10;
  }

  int isqrt = 0;
  while (isqrt*isqrt <= x) {
    isqrt++;
  }
  isqrt--;

  int cnt = 0;
  for (int i = 1; i <= isqrt; i++) {
    if (x % i == 0) {
      if (also(i)) {
        cnt++;
      }
      if (x / i != i && also(x / i)) {
        cnt++;
      }
    }
  }

  cout << cnt << endl;
}

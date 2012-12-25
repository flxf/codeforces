#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int a, x, y;
  cin >> a >> x >> y;

  if (y % a == 0) {
    cout << -1 << endl;
    return 0;
  }

  if (y < a) {
    if (abs(x) < (a + 1) / 2) {
      cout << 1 << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  }

  y -= a;
  int times = y / (2 * a);
  y = y % (2 * a);

  if (y < a) {
    if (abs(x) < (a + 1) / 2) {
      cout << 2 + times * 3 << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  } else {
    if (x > -1 * a && x < 0) {
      cout << 3 + times * 3 << endl;
    } else if (x < a && x > 0) {
      cout << 4 + times * 3 << endl;
    } else {
      cout << -1 << endl;
    }
  }
}

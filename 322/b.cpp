#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;

  int ans = 0;

  int rb = (r - 1) / 3;
  ans += rb;
  r -= rb * 3;

  int gb = (g - 1) / 3;
  ans += gb;
  g -= gb * 3;

  int bb = (b - 1) / 3;
  ans += bb;
  b -= bb * 3;

  ans = rb + gb + bb;

  int rem[3];
  rem[0] = r;
  rem[1] = b;
  rem[2] = g;
  sort(rem, rem+3);

  if (rem[0] == 2) {
    ans += 2;
  } else if (rem[0] == 1) {
    if (rem[1] == 3) {
      ans += 2;
    } else {
      ans += 1;
    }
  } else if (rem[0] == 3) {
    ans += 3;
  } else {
    if (rem[1] == 3) {
      ans += 2;
    } else if (rem[2] == 3) {
      ans += 1;
    }
  }

  cout << ans << endl;
}

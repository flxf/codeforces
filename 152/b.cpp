#include <iostream>
#include <utility>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int xc, yc;
  cin >> xc >> yc;

  int k;
  cin >> k;
  unsigned long long s = 0;

  int dx, dy;
  int sx, sy;
  for (int i = 0; i < k; i++) {
    cin >> dx >> dy;

    if (dx > 0) {
      sx = (n - xc) / dx;
    } else if (dx < 0) {
      sx = (1 - xc) / dx;
    } else {
      sx = 1000000001;
    }

    if (dy > 0) {
      sy = (m - yc) / dy;
    } else if (dy < 0) {
      sy = (1 - yc) / dy;
    } else {
      sy = 1000000001;
    }

    int add = min(sx, sy);
    //cout << add << endl;
    xc += add * dx;
    yc += add * dy;
    s += add;
  }

  cout << s << endl;
}

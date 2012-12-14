#include <iostream>

using namespace std;

int rec(int vp, int vd, int t, int princess_dist, int dragon_dist) {
  if (princess_dist * vd <= dragon_dist * vp) {
    return 0;
  }
  return 1 + rec(vp, vd, t, (dragon_dist - princess_dist) / (vd - vp)
}

int main() {
  int vp, vd, t, f, c;
  cin >> vp >> vd >> t >> f >> c;

  int princess_dist = c;
  int dragon_dist = c;
  if (princess_dist * vd < dragon_dist * vp) {
    return 0;
  }

  diff =
}

#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

#define PI 3.14159265358979323

using namespace std;

long double rads[100000];

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  int lastx, lasty;
  int x, y;
  long double ang;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    ang = atan2((long double)y, (long double)x);
    if (ang < 0) {
      ang += 2 * PI;
    }
    //cout << ang << endl;
    rads[i] = ang;
  }

  sort(rads, rads+n);

  if (rads[n - 1] - rads[0] < 0.000001) {
    cout << 0 << endl;
    return 0;
  }

  long double m = 2 * PI;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    long double dist = rads[j] - rads[i];
    if (dist < 0) {
      dist += 2 * PI;
    }

    dist = 2 * PI - dist;
    m = min(m, dist);
  }

  cout << setprecision(10) << m * (360.0 / (2 * PI)) << endl;
}

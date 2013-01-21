#include <cmath>
#include <iostream>
#include <iomanip>

#define PI 3.14159265358979323846

using namespace std;

int main() {
  int n, R, r;
  cin >> n >> R >> r;

  int can = -1;
  if (r > R) {
    can = 0;
  } else if (2 * r > R) {
    can = 1;
  } else if (2 * r == R) {
    can = 2;
  } else {
    long double r2 = r;
    long double R2 = R;
    long double theta = asin(r2 / (R2 - r2));

    long double cancan = floor((PI / theta) + 1e-6);
    can = (int) cancan;
  }

  if (n <= can) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

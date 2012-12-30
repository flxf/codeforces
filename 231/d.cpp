#include <iostream>

using namespace std;

int a[7];

int main() {
  int x, y, z;
  cin >> x >> y >> z;

  int x1, y1, z1;
  cin >> x1 >> y1 >> z1;

  for (int i = 1; i <= 6; i++) {
    cin >> a[i];
  }

  int tot = 0;
  if (z > z1) {
    tot += a[4];
  }
  if (z < 0) {
    tot += a[3];
  }
  if (x > x1) {
    tot += a[6];
  }
  if (x < 0) {
    tot += a[5];
  }
  if (y > y1) {
    tot += a[2];
  }
  if (y < 0) {
    tot += a[1];
  }

  cout << tot << endl;
}

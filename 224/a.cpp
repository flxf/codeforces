#include <iostream>
#include <algorithm>

using namespace std;

int a[3];

int main() {
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);

  for (int x = 1; x <= 10000; x++) {
    for (int y = 1; y <= 10000; y++) {
      if (x * y > a[0]) {
        break;
      }
      if (x * y != a[0]) {
        continue;
      }
      if (a[1] % y != 0) {
        continue;
      }
      int z = a[1] / y;

      if (x * z == a[2]) {
        cout << 4*x + 4*y + 4*z << endl;
        return 0;
      }
    }
  }
}

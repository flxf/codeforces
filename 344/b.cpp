#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int bonds[3];

  for (int ab = 0; ab <= 1000000; ab++) {
    if (ab > a || ab > b) {
      break;
    }

    int ac = a - ab;
    int bc = b - ab;

    if (ac + bc != c) {
      continue;
    }

    bonds[0] = ab;
    bonds[1] = ac;
    bonds[2] = bc;
    sort(bonds, bonds+2);

    if (bonds[0] < 0) {
      continue;
    }

    if (bonds[1] == 0) {
      continue;
    }

    cout << ab << " " << bc << " " << ac << endl;
    return 0;
  }

  cout << "Impossible" << endl;
}

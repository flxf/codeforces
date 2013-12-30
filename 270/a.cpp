#include <iostream>

bool possible[180];

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int ang = 3; ang <= 360; ang++) {
    if (360 % ang == 0) {
      int h = 180 - 360 / ang;
      possible[h] = true;
    }
  }

  int angle;
  for (int i = 0; i < t; i++) {
    cin >> angle;
    if (possible[angle]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

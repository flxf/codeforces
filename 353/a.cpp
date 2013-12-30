#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  bool can = false;
  int a = 0;
  int b = 0;
  for (int i = 0; i < n; i++) {
    int up, down;
    cin >> up >> down;

    if ((up % 2) != (down % 2)) {
      can = true;
    }

    a += up;
    b += down;
  }

  if ((a % 2) == (b % 2)) {
    if (a % 2 == 0) {
      cout << 0 << endl;
    } else if (can) {
      cout << 1 << endl;
    } else {
      cout << -1 << endl;
    }
  } else {
    cout << -1 << endl;
  }
}

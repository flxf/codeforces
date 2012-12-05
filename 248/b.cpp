#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int d = 2*3*5*7;
  int n;
  cin >> n;

  int m = 1;
  for (int i = 1; i < n; i++) {
    m = (m * 10) % d;
  }

  if (n <= 2) {
    cout << -1 << endl;
  } else if (n == 3) {
    cout << 210 << endl;
  } else {
    cout << 1;
    for (int i = 0; i < n - 4; i++) {
      cout << 0;
    }
    cout << setfill('0') << setw(3) << d - m << endl;
  }
}

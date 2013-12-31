#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int ones = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == 1) {
      ones++;
    }
  }

  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;

    int num = r - l + 1;
    if (num % 2 == 0) {
      if (ones >= num / 2 && (n - ones) >= num / 2) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else {
      cout << 0 << endl;
    }
  }
}

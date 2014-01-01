#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  bool edge = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      if (a == 1 && (i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
        edge = true;
      }
    }
  }

  if (edge) {
    cout << 2 << endl;
  } else {
    cout << 4 << endl;
  }
}

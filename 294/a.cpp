#include <iostream>

using namespace std;

int a[100];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;

    int up = y - 1;
    int down = a[x] - y;
    a[x] = 0;
    if (x > 0) {
      a[x - 1] += up;
    }
    if (x < n - 1) {
      a[x + 1] += down;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
}

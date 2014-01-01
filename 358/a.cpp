#include <iostream>

using namespace std;

bool intersect(int x, int y, int u, int v) {
  int l = min(x, y);
  int r = max(x, y);

  if (l < u && u < r) {
    return (v < l || v > r);
  } else if (l < v && v < r) {
    return (u < l || u > r);
  }
  return false;
}

int main() {
  int n;
  cin >> n;

  if (n <= 2) {
    cout << "no" << endl;
    return 0;
  }

  int x[1000];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  for (int i = 1; i < n; i++) {
    int l = x[i - 1];
    int r = x[i];
    for (int j = 1; j < i; j++) {
      if (intersect(l, r, x[j], x[j - 1])) {
        cout << "yes" << endl;
        return 0;
      }
    }
  }

  cout << "no" << endl;
}

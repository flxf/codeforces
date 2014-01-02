#include <iostream>

using namespace std;

long long a[100000];
long long y = 0;

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;

    if (t == 1) {
      int v, x;
      cin >> v >> x;
      a[v - 1] = x - y;
    } else if (t == 2) {
      int yi;
      cin >> yi;
      
      y += yi;
    } else {
      int q;
      cin >> q;

      cout << a[q - 1] + y << endl;
    }
  }
}

#include <iostream>

using namespace std;

int list[100000];

int main() {
  int n, m;
  cin >> n >> m;

  int total = 0;
  for (int i = 0; i < n; i++) {
    int c, t;
    cin >> c >> t;

    total += c * t;
    list[i] = total;
  }

  int iter = 0;
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;

    while (true) {
      if (v <= list[iter]) {
        cout << iter + 1 << endl;
        break;
      }
      iter++;
    }
  }
}

#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < 4; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int u = min(a, b);
    int v = min(c, d);

    if (n >= u + v) {
      cout << i + 1 << " " << u << " " << n - u << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}

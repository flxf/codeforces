#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int x;
  cin >> x;

  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (x == a || x == 7 - a || x == b || x == 7 - b) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}

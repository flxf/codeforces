#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n  >> m;

  int x = min(n, m);
  cout << x + 1 << endl;
  for (int i = 0; i <= x; i++) {
    cout << (x - i) << " " << i << endl;
  }
}

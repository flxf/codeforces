#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int mx = n + ((m == 0) ? 0 : m - 1);
  int mn = n + max(0, m - n);

  if (n == 0 && m > 0) {
    cout << "Impossible" << endl;
    return 0;
  }

  cout << mn << " " << mx << endl;
}

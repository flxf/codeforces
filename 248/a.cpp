#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int lc = 0, rc = 0;
  int l, r;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    lc += l;
    rc += r;
  }

  cout << min(min(min(n - lc + rc, n - rc + lc), lc + rc), n - lc + n - rc)  << endl;
}

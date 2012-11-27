#include <iostream>

using namespace std;

int main() {
  int y, k, n;
  cin >> y >> k >> n;

  // round y up to next k
  int s = (y + (k - 1)) / k * k;
  s -= y;
  if (s == 0) {
    s = k;
  }

  if (s > n - y) {
    cout << -1 << endl;
    return 0;
  }

  //cout << ((n - y) - s) / k + 1 << endl;
  for (int i = s; i <= n - y; i += k) {
    cout << i << " ";
  }
  cout << endl;
}

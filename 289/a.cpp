#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  unsigned long long sm = 0;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    sm += (r - l) + 1;
  }

  if (sm % k == 0) {
    cout << 0 << endl;
  } else {
    int ans = k - (sm % k);
    cout << ans << endl;
  }
}

#include <iostream>

using namespace std;

int seen[5001];

int main() {
  int n;
  cin >> n;

  int mx = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    
    mx = max(a, mx);
    seen[a]++;
  }

  int ans = 0;
  for (int i = 1; i <= 5000; i++) {
    if (i == mx) {
      ans += min(seen[i], 1);
    } else {
      ans += min(seen[i], 2);
    }
  }

  cout << ans << endl;
  for (int i = 1; i <= 5000; i++) {
    if (seen[i] > 0) {
      cout << i << " ";
    }
  }
  for (int i = mx - 1; i >= 0; i--) {
    if (seen[i] > 1) {
      cout << i << " ";
    }
  }
  cout << endl;
}

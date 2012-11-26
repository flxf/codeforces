#include <iostream>

using namespace std;

pair<int, int> s[100000];

int main() {
  int n;
  cin >> n;

  int a, b;
  int mn = 2000000000;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    s[i] = make_pair(a, b);
    mx = max(mx, b);
    mn = min(mn, a);
  }

  for (int i = 0; i < n; i++) {
    if (s[i].first == mn && s[i].second == mx) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}

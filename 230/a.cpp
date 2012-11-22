#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> d[1000];

int main() {
  int s, n;
  cin >> s >> n;

  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    d[i] = make_pair(a, b);
  }

  sort(d, d+n);
  for (int i = 0; i < n; i++) {
    if (s <= d[i].first) {
      cout << "NO" << endl;
      return 0;
    }
    s += d[i].second;
  }

  cout << "YES" << endl;
}

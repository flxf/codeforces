#include <iostream>
#include <set>

using namespace std;

set<int> nb[100000];
int c[100000];

int main() {
  int n, m;
  cin >> n >> m;

  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    v--;
    c[i] = v;
  }

  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;

    if (c[a] != c[b]) {
      nb[c[a]].insert(c[b]);
      nb[c[b]].insert(c[a]);
    }
  }

  int best = c[0];
  for (int i = 0; i < n; i++) {
    if (nb[c[i]].size() > nb[best].size()) {
      best = c[i];
    } else if (nb[c[i]].size() == nb[best].size() && c[i] < best) {
      best = c[i];
    }
  }

  cout << best + 1 << endl;
}

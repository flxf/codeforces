#include <iostream>

using namespace std;

bool dict[1001];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    dict[a] = true;
    dict[b] = true;
  }

  int chosen;
  for (int i = 1; i <= n; i++) {
    if (!dict[i]) {
      chosen = i;
      break;
    }
  }

  cout << n - 1 << endl;
  for (int i = 1; i <= n; i++) {
    if (i != chosen) {
      cout << i << " " << chosen << endl;
    }
  }
}

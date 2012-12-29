#include <iostream>

using namespace std;

int a[101];

int main() {
  int n;
  cin >> n;

  if (n % 2 == 0 || n == 1) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int moves = 0;
  for (int i = n; i >= 3; i -= 2) {
    int dis = i;
    int bef = i - 1;
    int neg = i / 2;

    int m = max(a[dis], a[bef]);
    moves += m;
    a[dis] = 0;
    a[bef] = 0;
    a[neg] = max(a[neg] - m, 0);
  }

  moves += a[1];
  cout << moves << endl;
}

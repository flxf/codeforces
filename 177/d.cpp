#include <iostream>

using namespace std;

#define ull unsigned long long

ull a[100000];
ull b[100000];

ull range(int x, int y) {
  if (x == 0) {
    return b[y];
  } else {
    return b[y] - b[x - 1];
  }
}

int main() {
  int n, m, c;
  cin >> n >> m >> c;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 1; i < m; i++) {
    b[i] = (b[i - 1] + b[i]);
  }

  for (int i = 0; i < n; i++) {
    int leftmost = max(0, i - (n - m));
    int rightmost = min(m - 1, i);
    ull sum = range(leftmost, rightmost);
    a[i] += sum;
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] % c << " ";
  }
  cout << endl;
}

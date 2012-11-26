#include <iostream>
#include <algorithm>

using namespace std;

int a[1000];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  sort(a, a+m);

  int minq = 0;
  int maxq = 0;
  int mintot = 0;
  int maxtot = 0;

  int x = 0;
  while (minq < n) {
    int add = min(a[x], n - minq);
    minq += add;
    mintot += (add * (add + 1)) / 2;
    x++;
  }

  x = m - 1;
  while (maxq < n) {
    int add = min(a[x], n - maxq);
    maxq += add;
    maxtot += (add * (add + 1)) / 2;
    x--;
  }

  cout << maxtot << " " << mintot << endl;
}






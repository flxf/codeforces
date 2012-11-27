#include <iostream>
#include <algorithm>

using namespace std;

int a[1000];
int c[1001];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> a[i];
    c[a[i]]++;
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
    // first + last * (n / 2)
    mintot += (a[x] + (a[x] - add + 1)) * add / 2;
    //mintot += (add * (add + 1)) / 2; // THS IS WRONG
    x++;
  }

  for (int i = 1000; i >= 1; i--) {
    int add = min(c[i], n - maxq);
    c[i - 1] += c[i];
    maxq += add;
    maxtot += add * i;
  }

  cout << maxtot << " " << mintot << endl;
}






#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  unsigned long long a, b, c, d;
  a = 1;
  b = 1;
  c = 1;
  d = 0;

  unsigned long long na, nb, nc, nd;
  for (int i = 2; i <= n; i++) {
    nd = (a + b + c) % 1000000007;
    na = (d + b + c) % 1000000007;
    nb = (a + c + d) % 1000000007;
    nc = (d + a + b) % 1000000007;
    a = na;
    b = nb;
    c = nc;
    d = nd;
  }

  cout << d << endl;
}

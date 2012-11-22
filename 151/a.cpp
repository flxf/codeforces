#include <iostream>

using namespace std;

int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;

  int slices = c * d;
  int sug = p / np;
  int cups = (k * l) / nl;

  int pours = min(slices, min(sug, cups));
  cout << pours / n << endl;
}

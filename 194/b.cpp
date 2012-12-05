#include <iostream>
#define ULL unsigned long long

using namespace std;

unsigned long long gcd(ULL n, ULL d) {
  if (d == 0) {
    return n;
  }
  return gcd(d, n % d);
}

unsigned long long lcm(ULL n, ULL d) {
  unsigned long long g = gcd(n, d);
  return n * d / g;
}

int main() {
  int t;
  cin >> t;

  ULL n, s, v;
  for (int i = 0; i < t; i++) {
    cin >> n;
    s = n*4;
    v = n+1;
    //cout << s << "*" << lcm(s, v) / s << endl;
    //cout << v << "*" << lcm(s, v) / v << endl;
    cout << lcm(s, v) / v + 1 << endl;
  }
}

#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int topl = lcm(a, c);
  int x = (topl / a);
  int y = (topl / c);

  int diff = b * x - d * y;
  int denom = b * x;
  int g = gcd(diff, denom);

  if (diff >= 0) {
    cout << diff / g << "/" << denom / g << endl;
    return 0;
  }

  topl = lcm(b, d);
  x = (topl / b);
  y = (topl / d);

  diff = a * x - c * y;
  denom = a * x;
  g = gcd(diff, denom);
  cout << diff / g << "/" << denom / g << endl;
}

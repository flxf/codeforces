#include <iostream>

using namespace std;

int gers[100];

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> gers[i];
  }

  int g = gers[0];
  for (int i = 1; i < n; i++) {
    g = gcd(gers[i], g);
  }

  cout << g * n << endl;
}

#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int res = 0;
  while (a >= b) {
    res += (a / b) * b;
    a = (a % b) + (a / b);
  }

  res += a;
  cout << res << endl;
}

#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << a*c + a*b + b*c - c - b - a + 1 << endl;
}

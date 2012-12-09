#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int start = 1;
  int angle = 1;
  for (int i = 2; i <= n; i++) {
    angle += 2;
    start += 6 * angle - 6;
  }
  cout << start << endl;
}

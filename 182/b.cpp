#include <iostream>

using namespace std;

int main() {
  int d, n;
  cin >> d >> n;

  int v;
  int total = 0;
  for (int i = 0; i < n - 1; i++) {
    cin >> v;
    total += (d - v);
  }
  cout << total << endl;

  BINARY THEN LINEAR SEARCH OVER SMALL RANGE
}

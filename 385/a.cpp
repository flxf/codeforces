#include <iostream>

using namespace std;

int main() {
  int n, c;
  cin >> n >> c;

  int last;
  cin >> last;

  int best = 0;
  for (int i = 1; i < n; i++) {
    int now;
    cin >> now;

    best = max(best, last - now - c);
    last = now;
  }

  cout << best << endl;
}

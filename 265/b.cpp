#include <iostream>
#include <cmath>

using namespace std;

int h[100000];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  int cost = n - 1 + h[0] + n;
  int pos = h[0];

  for (int i = 1; i < n; i++) {
    cost += abs(h[i] - h[i - 1]);
  }

  cout << cost << endl;
}

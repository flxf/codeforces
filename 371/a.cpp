#include <iostream>

using namespace std;

int a[100];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int cost = 0;

  for (int i = 0; i < k; i++) {
    int ones = 0, twos = 0;
    for (int j = i; j < n; j += k) {
      if (a[j] == 1) {
        ones++;
      } else {
        twos++;
      }
    }

    cost += min(ones, twos);
  }

  cout << cost << endl;
}

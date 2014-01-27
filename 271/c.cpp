#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  if (n / k < 3) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < 2 * k; i++) {
    cout << (i / 2) % k + 1 << " ";
  }

  for (int i = 2 * k; i < n; i++) {
    cout << i % k + 1 << " ";
  }
  cout << endl;

  return 0;
}

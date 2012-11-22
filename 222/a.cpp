#include <iostream>

using namespace std;

int a[100000];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = k; i < n; i++) {
    if (a[i] != a[i - 1]) {
      cout << -1 << endl;
      return 0;
    }
  }

  int needed = a[k-1];
  for (int i = k - 1; i >= 0; i--) {
    if (a[i] != needed) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}

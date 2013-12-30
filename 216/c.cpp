#include <iostream>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  if (n == m) {
    cout << 2 * k + 2 << endl;
    for (int i = 0; i < k; i++) {
      cout << 1 << " ";
    }
    cout << 2 << " ";
    for (int i = 0; i < k; i++) {
      cout << 1 + n << " ";
    }
    cout << 2 + n << endl;
  } else {
    cout << 2 * k << endl;
    for (int i = 0; i < k; i++) {
      cout << 1 << " ";
    }
    for (int i = 0; i < k; i++) {
      cout << m + 1 << " ";
    }
    cout << endl;
  }
}

#include <iostream>

using namespace std;

int a[30];
int a_inv[901];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int slice;
    cin >> slice;
    a[i] = slice;
    a_inv[slice] = (i + 1);
  }

  int pos = 1;
  for (int i = 0; i < k; i++) {
    cout << a[i];
    for (int j = 1; j < n; j++) {
      while (true) {
        if (a_inv[pos] == 0) {
          cout << " " << pos;
          pos++;
          break;
        }
        pos++;
      }
    }
    cout << endl;
  }

  return 0;
}

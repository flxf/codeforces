#include <iostream>

using namespace std;

int a[100000];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  int last = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > a[i + 1]) {
      break;
    }
    last = i;
  }

  cout << last << endl;
}

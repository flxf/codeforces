#include <iostream>

using namespace std;

int a[100000];

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  int best = 2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int l1 = a[1];
  int l2 = a[0];
  int curr = 2;
  for (int i = 2; i < n; i++) {
    if (l1 + l2 == a[i]) {
      curr++;
    } else {
      best = max(best, curr);
      curr = 2;
    }

    l1 = a[i];
    l2 = a[i - 1];
  }

  best = max(best, curr);
  cout << best << endl;
}

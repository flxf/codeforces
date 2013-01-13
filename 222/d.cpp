#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];
int b[100000];

int main() {
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  sort(a,a+n);
  reverse(a, a+n);
  sort(b,b+n);

  int wins = 0;
  int start = 0;
  for (int i = 0; i < n; i++) {
    int req = x - a[i];
    int fnd = lower_bound(b + start, b + n, req) - b;
    if (fnd == n) { // no ans
      if (start == i) {
        start++;
      }
    } else {
      wins++;
      start = fnd + 1;
    }
  }

  cout << 1 << " " << wins << endl;
}

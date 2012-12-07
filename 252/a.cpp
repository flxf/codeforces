#include <iostream>
#include <cmath>

using namespace std;

int a[100];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int mx = 0;
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = i; j < n; j++) {
      cur = cur ^ a[j];
      //cout << i << ":" << j << ":" << cur << endl;
      mx = max(mx, cur);
    }
  }

  cout << mx << endl;
}

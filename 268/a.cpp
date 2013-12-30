#include <iostream>

using namespace std;

int h[100];
int a[100];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> h[i] >> a[i];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        if (h[i] == a[j]) {
          ans++;
        }
      }
    }
  }

  cout << ans << endl;
}

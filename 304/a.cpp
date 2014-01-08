#include <iostream>

using namespace std;

bool issquare[100000001];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i <= 10000; i++) {
    issquare[i * i] = true;
  }

  int ans = 0;

  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int c = i * i + j * j;
      if (c > n * n) {
        break;
      }

      if (issquare[c]) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}

#include <iostream>

using namespace std;

int a[100];
int b[100];
bool opened[101];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }

      if (a[j] == b[i]) {
        opened[j] = true;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (opened[i]) {
      ans++;
    }
  }

  cout << n - ans << endl;
}

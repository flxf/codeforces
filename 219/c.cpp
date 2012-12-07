#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char ring(char a, char b) {
  a = min('C', a);
  b = min('C', b);
  if (a > b) {
    swap(a, b);
  }
  if (a


}

int main() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  if (k == 2) {
    int swa = 0, swb = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != (char)('A' + (i % 2))) {
        swa++;
      } else {
        swb++;
      }
    }

    if (swa < swb) {
      cout << swa << endl;
      for (int i = 0; i < n; i++) {
        cout << (char)('A' + (i % 2));
      }
      cout << endl;
    } else {
      cout << swb << endl;
      for (int i = 0; i < n; i++) {
        cout << (char)('A' + ((i + 1) % 2));
      }
      cout << endl;
    }
  } else {
    int c = 0;
    for (int i = 1; i < n - 1; i++) {
      if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
        continue;
      } else {
      }
    }
  }
}

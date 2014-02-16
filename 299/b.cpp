#include <iostream>
#include <string>

using namespace std;

bool possible[1000000];

int main() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  if (n <= k + 1) {
    cout << "YES" << endl;
    return 0;
  }

  int many = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] == '.') {
      many += 1;
    }
    possible[i] = (s[i] == '.');
  }

  for (int i = k; i < n; i++) {
    if (s[i] == '#') {
      possible[i] = false;
    } else {
      if (many > 0) {
        possible[i] = true;
      } else {
        possible[i] = false;
      }
    }

    if (possible[i - k]) {
      many--;
    }
    if (possible[i]) {
      many++;
    }
  }

  if (possible[n - 1]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

}

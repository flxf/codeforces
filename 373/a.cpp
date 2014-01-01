#include <iostream>

using namespace std;

int dict[10];

int main() {
  int k;
  cin >> k;

  for (int i = 0; i < 16; i++) {
    char c;
    cin >> c;

    if (c != '.') {
      dict[c - '0']++;
    }
  }

  for (int i = 1; i <= 9; i++) {
    if (dict[i] > k * 2) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}

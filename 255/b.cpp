#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  int x = 0, y = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'x') {
      x++;
    } else {
      y++;
    }
  }

  if (x > y) {
    for (int i = 0; i < x - y; i++) {
      cout << 'x';
    }
    cout << endl;
  } else {
    for (int i = 0; i < y - x; i++) {
      cout << 'y';
    }
    cout << endl;
  }
}

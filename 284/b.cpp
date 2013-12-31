#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int a = 0;
  int f = 0;
  int x = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      a++;
    } else if (s[i] == 'F') {
      f++;
    } else {
      x++;
    }
  }

  if (x == 0) {
    cout << a << endl;
  } else if (x == 1) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
}

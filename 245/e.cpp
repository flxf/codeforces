#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
  string s;
  cin >> s;

  int mx = 0;
  int mn = 0;
  int cur = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '+') {
      cur++;
    } else {
      cur--;
    }

    mx = max(mx, cur);
    mn = min(mn, cur);
  }

  mn = mn * -1;
  cout << mn + mx << endl;
}

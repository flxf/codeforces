#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  int a, b, n;
  cin >> a >> b >> n;

  a *= 10;
  int added = -1;
  for (int i = 0; i <= 9; i++) {
    if ((a + i) % b == 0) {
      added = i;
    }
  }

  stringstream ans;
  if (added == -1) {
    cout << -1 << endl;
    return 0;
  } else {
    a += added;
    ans << a;
    string s = ans.str();
    cout << s;
    for (int i = 1; i < n; i++) {
      cout << "0";
    }
    cout << endl;
  }
}

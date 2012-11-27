#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;

  if (a.size() != b.size()) {
    cout << "NO" << endl;
    return 0;
  }

  int cnt = 0;
  int p[2];
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) {
      if (cnt == 2) {
        cout << "NO" << endl;
        return 0;
      }

      p[cnt] = i;
      cnt++;
    }
  }

  if (cnt == 2 && a[p[0]] == b[p[1]] && a[p[1]] == b[p[0]]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

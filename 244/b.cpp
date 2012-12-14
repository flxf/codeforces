#include <iostream>
#include <set>

using namespace std;

set<unsigned long long> s;
int n;

void rec(unsigned long long a, int x, int y) {
  if (a > n) {
    return;
  }

  s.insert(a);
  rec(a * 10 + x, x, y);
  rec(a * 10 + y, x, y);
}

int main() {
  cin >> n;

  for (int i = 0; i <= 9; i++) {
    for (int j = i + 1; j <= 9; j++) {
      if (i != 0) {
        rec(0, i, j);
      }
      rec(j, i, j);
    }
  }

  cout << s.size() - 1 << endl;
}

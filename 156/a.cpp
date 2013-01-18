#include <iostream>
#include <string>

using namespace std;

char get(string &v, int pos) {
  if (pos < 0) {
    return 0;
  }
  if (pos >= v.length()) {
    return 0;
  }
  return v[pos];
}

int main() {
  string s, u;
  cin >> s >> u;

  int best = u.length();
  int start = -1 * u.length() + 1;
  int end = s.length() - 1;

  for (int i = start; i <= end; i++) {
    int cost = 0;
    for (int j = 0; j < u.length(); j++) {
      char from_s = get(s, i + j);
      char from_u = get(u, j);

      if (from_s == 0) {
        cost++;
      } else if (from_s != from_u) {
        cost++;
      }
    }

    best = min(best, cost);
  }

  cout << best << endl;
}

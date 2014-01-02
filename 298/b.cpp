#include <iostream>
#include <string>

using namespace std;

int main() {
  int t, sx, sy, ex, ey;
  cin >> t >> sx >> sy >> ex >> ey;

  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'S' && ey < sy) {
      sy--;
    } else if (s[i] == 'E' && ex > sx) {
      sx++;
    } else if (s[i] == 'N' && ey > sy) {
      sy++;
    } else if (s[i] == 'W' && ex < sx) {
      sx--;
    }

    if (sx == ex && sy == ey) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}

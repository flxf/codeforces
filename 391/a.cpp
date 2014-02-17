#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  char last = ' ';
  int lastcnt = -1;
  int events = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == last) {
      lastcnt++;
    } else {
      if (lastcnt % 2 == 0) {
        events++;
      }

      lastcnt = 1;
      last = s[i];
    }
  }

  if (lastcnt % 2 == 0) {
    events++;
  }

  cout << events << endl;
}

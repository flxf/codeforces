#include <iostream>
#include <string>

using namespace std;

int dict[26];

int main() {
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    dict[s[i] - 'a']++;
  }

  int odds = 0;
  for (int i = 0; i < 26; i++) {
    if (dict[i] % 2 != 0) {
      odds++;
    }
  }

  if (odds == 0) {
    cout << "First" << endl;
  } else if (odds % 2 == 1) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
}

#include <iostream>
#include <string>

using namespace std;

int map[26];


int main() {
  int k;
  cin >> k;

  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    map[s[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (map[i] % k != 0) {
      cout << -1 << endl;
      return 0;
    } else {
      map[i] /= k;
    }
  }

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 26; j++) {
      for (int a = 0; a < map[j]; a++) {
        cout << (char)(j + 'a');
      }
    }
  }
  cout << endl;
}

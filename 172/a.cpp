#include <iostream>
#include <string>

using namespace std;

string s[30000];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  int i;
  for (i = 0; i < s[0].size(); i++) {
    for (int j = 1; j < n; j++) {
      if (s[j][i] != s[j - 1][i]) {
        goto done;
      }
    }
  }

  done:
  cout << i << endl;
}

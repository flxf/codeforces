#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int ans = 0;
  for (int i = n; i < s.size(); i += n) {
    if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3]) {
      ans++;
    }
  }

  cout << ans << endl;
}

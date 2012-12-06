#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string a, s;
  cin >> a >> s;

  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());

  int j = 0;
  for (int i = 0; i < a.size(); i++) {
    if (j < s.size() && a[i] < s[j]) {
      a[i] = s[j];
      j++;
    }
  }

  cout << a << endl;
}

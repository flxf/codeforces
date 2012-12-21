#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

char best[100001];
int len = 1;

int main() {
  string s;
  cin >> s;

  best[0] = s[0];
  for (int i = 1; i < s.size(); i++) {
    int pos = upper_bound(best, best+len, s[i], greater<char>() ) - best;
    best[pos] = s[i];
    len = pos + 1;
  }

  for (int i = 0; i < len; i++) {
    cout << best[i];
  }
  cout << endl;
}

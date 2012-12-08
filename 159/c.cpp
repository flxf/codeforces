#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<int> pos[26];

int main() {
  int k;
  cin >> k;

  string s;
  cin >> s;

  string ans = "";
  for (int i = 0; i < k; i++) {
    ans += s;
  }

  for (int i = 0; i < ans.size(); i++) {
    pos[ans[i] - 'a'].push_back(i);
  }

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int p;
    char c;
    cin >> p >> c;

    int x = pos
  }
}

#include <iostream>
#include <string>

using namespace std;

bool dict[256];

int main() {
  int n, k;
  cin >> n >> k;

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for (int j = '0'; j <= '9'; j++) {
      dict[j] = false;
    }
    for (int j = 0; j < s.size(); j++) {
      dict[s[j]] = true;
    }

    bool good = true;
    for (int j = '0'; j <= '0' + k; j++) {
      good = good && dict[j];
    }

    if (good) {
      cnt++;
    }
  }

  cout << cnt << endl;
}

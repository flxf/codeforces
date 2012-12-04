#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> x;
vector<int> len;
vector<bool> even;

int main() {
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    // odd length
    int j = 1;
    while (i - j >= 0 && i + j < s.size()) {
      if (s[i - j] != s[i + j]) {
        break;
      }
      j++;
    }
    j--;

    x.push_back(i);
    len.push_back(1 + j);
    even.push_back(false);

    j = 1;
    while (i - j + 1 >= 0 && i + j < cnt) {
      if (s[i - j + 1] != s[i + j]) {
        break;
      }
      j++;
    }
    j--;

    if (j > 0) {
      x.push_back(i+1);
      len.push_back(j);
      even.push_back(true);
    }
  }

  for (int i = 0; i < x.size(); i++) {
    for (int j = i + 1; j < x.size(); j++) {
      if (x[i] == x[j]) {
        continue;
      }
      int l, r;
      if (x[i] < x[j]) {
        l = i;
        r = j;
      } else {
        r = i;
        l = j;
      }

      int dist = x[r] - x[l];
      int maxsect = min((x[l] + len[l]) - (x[r] - len[r]), dist);
      maxsect = max(maxsect, 0);
      int sub = maxsect * (maxsect + 1) / 2;
      cout << len[r] * len[l] - sub << endl;
    }
  }
}

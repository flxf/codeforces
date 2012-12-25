#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > palins;

bool byend(pair<int, int> a, pair<int, int> b) {
  if (a.second <= b.second) {
    return true;
  }
  return false;
}

int endat[2000];
int startat[2000];

int main() {
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    // odd length
    int j = 0;
    while (i - j >= 0 && i + j < s.size()) {
      if (s[i - j] != s[i + j]) {
        break;
      }
      palins.push_back(make_pair(i - j, i + j));
      j++;
    }

    j = 1;
    while (i - j + 1 >= 0 && i + j < s.size()) {
      if (s[i - j + 1] != s[i + j]) {
        break;
      }
      palins.push_back(make_pair(i - j + 1, i + j));
      j++;
    }
  }
  //sort(palins.begin(), palins.end());

  for (int i = 0; i < palins.size(); i++) {
    startat[palins[i].first]++;
    endat[palins[i].second]++;
  }

  for (int i = 1; i < 2000; i++) {
    endat[i] = endat[i - 1] + endat[i];
  }
  for (int i = 1998; i >= 0; i--) {
    startat[i] = startat[i + 1] + startat[i];
  }

  unsigned long long tot = 0;
  for (int i = 0; i < palins.size(); i++) {
    //cout << palins[i].first << ":" << palins[i].second << endl;
    if (palins[i].first > 0) {
      tot += endat[palins[i].first - 1];
    }
    if (palins[i].second < s.size() - 1) {
      tot += startat[palins[i].second + 1];
    }
  }
  tot /= 2;
  cout << tot << endl;
}

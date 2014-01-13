#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;

  vector<pair<char, int> > encoded;

  char last = s[0];
  int cnt = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == last) {
      cnt++;
    } else {
      encoded.push_back(make_pair(last, min(cnt, 2)));
      last = s[i];
      cnt = 1;
    }
  }
  encoded.push_back(make_pair(last, min(cnt, 2)));

  for (int i = 1; i < encoded.size() - 1; i++) {
    if (encoded[i].second == 2 && encoded[i - 1].second == 2 && encoded[i + 1].second == 2) {
      encoded[i].second = 1;
    }
  }
  for (int i = 0; i < encoded.size() - 1; i++) {
    if (encoded[i].second == 2 && encoded[i + 1].second == 2) {
      encoded[i].second = 1;
    }
  }

  for (int i = 0; i < encoded.size(); i++) {
    for (int j = 0; j < encoded[i].second; j++) {
      cout << encoded[i].first;
    }
  }
  cout << endl;
}

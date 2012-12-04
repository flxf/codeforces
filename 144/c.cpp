#include <iostream>

using namespace std;

int bcnt[26];
int acnt[26];
int wildcards;

bool comp() {
  int changes = 0;
  for (int i = 0; i < 26; i++) {
    if (acnt[i] > bcnt[i]) {
      return false;
    }
    changes += bcnt[i] - acnt[i];
  }
  return wildcards == changes;
}

int main() {
  wildcards = 0;
  string a, b;
  cin >> a >> b;

  if (b.size() > a.size()) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 0; i < b.size(); i++) {
    bcnt[b[i] - 'a']++;
  }

  for (int i = 0; i < b.size(); i++) {
    if (a[i] == '?') {
      wildcards++;
    } else {
      acnt[a[i] - 'a']++;
    }
  }

  int sol = 0;

  if (comp()) {
    sol++;
  }

  for (int i = b.size(); i < a.size(); i++) {
    int last = i - b.size();
    if (a[last] == '?') {
      wildcards--;
    } else {
      acnt[a[last] - 'a']--;
    }

    if (a[i] == '?') {
      wildcards++;
    } else {
      acnt[a[i] - 'a']++;
    }

    if (comp()) {
      sol++;
    }
  }

  cout << sol << endl;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

pair<int, string> names[3000];
int pos[3000];
int have[3000];
bool used[3000];
int assign[3000];

int main() {
  int n;
  cin >> n;

  string name;
  int h;
  for (int i = 0; i < n; i++) {
    cin >> name >> h;
    names[i] = make_pair(h, name);
    pos[i] = -1;
  }
  sort(names, names+n);

  //for (int i = 0; i < n; i++) {
    //cout << names[i].first << ":" << names[i].second << endl;
  //}

  for (int i = n - 1; i >= 0; i--) {
    int push = i;
    int points = n - i;
    int needed = 0;
    for (int i = 0; i < n; i++) {
      if (names[i].first >= points) {
        needed = n - i;
        break;
      }
    }

    if (needed == 0) {
      break;
    }

    for (int j = n - needed - 1; ; j--) {
      if (j < 0) {
        cout << -1 << endl;
        return 0;
      }

      if (pos[j] == -1) {
        pos[j] = push;
        break;
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (pos[i] == -1) {
      pos[i] = cnt;
      cnt++;
    }

    //cout << pos[i] << endl;
  }

  have[0] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (pos[j] > pos[i]) {
        have[i]++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (have[i] == names[j].first && !used[j]) {
        assign[i] = j;
        used[j] = true;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << names[assign[i]].second << " " << (pos[i] + 1) << endl;
  }
}

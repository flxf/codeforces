#include <iostream>
#include <vector>

using namespace std;

vector<int> pos[100001];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    pos[a].push_back(i);
  }

  int cnt = 0;

  for (int i = 1; i <= 100000; i++) {
    if (pos[i].size() == 0) {
      continue;
    } else if (pos[i].size() == 1) {
      //cout << i << " " << 0 << endl;
      cnt++;
      continue;
    }

    int d = pos[i][1] - pos[i][0];
    bool good = true;
    for (int j = 2; j < pos[i].size(); j++) {
      if (pos[i][j] - pos[i][j - 1] != d) {
        good = false;
        break;
      }
    }

    if (good) {
      cnt++;
      //cout << i << " " << d << endl;
    }
  }

  cout << cnt << endl;

  for (int i = 1; i <= 100000; i++) {
    if (pos[i].size() == 0) {
      continue;
    } else if (pos[i].size() == 1) {
      cout << i << " " << 0 << endl;
      continue;
    }

    int d = pos[i][1] - pos[i][0];
    bool good = true;
    for (int j = 2; j < pos[i].size(); j++) {
      if (pos[i][j] - pos[i][j - 1] != d) {
        good = false;
        break;
      }
    }

    if (good) {
      cout << i << " " << d << endl;
    }
  }
}

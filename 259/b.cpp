#include <iostream>

using namespace std;

int ms[3][3];

void solve() {
  int sum = ms[0][0] + ms[0][1] + ms[0][2];
  ms[1][1] = sum - ms[1][0] - ms[1][2];
  ms[2][2] = sum - ms[2][0] - ms[2][1];
}

bool verify() {
  int sum = ms[0][0] + ms[0][1] + ms[0][2];
  for (int i = 0; i < 3; i++) {
    int cs = 0;
    for (int j = 0; j < 3; j++) {
      cs += ms[i][j];
    }
    if (cs != sum) {
      return false;
    }
  }

  for (int i = 0; i < 3; i++) {
    int cs = 0;
    for (int j = 0; j < 3; j++) {
      cs += ms[j][i];
    }
    if (cs != sum) {
      return false;
    }
  }

  int ds = ms[0][0] + ms[1][1] + ms[2][2];
  if (ds != sum) {
    return false;
  }

  ds = ms[0][2] + ms[1][1] + ms[2][0];
  if (ds != sum) {
    return false;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (ms[i][j] <= 0) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> ms[i][j];
    }
  }

  for (int x = 1; x <= 100000; x++) {
    ms[0][0] = x;
    solve();
    if (verify()) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          cout << ms[i][j] << " ";
        }
        cout << endl;
      }
    }
  }
}

#include <iostream>
#include <algorithm>

using namespace std;

int dig[100000];

int modded2[2];
int modded1[2];

#define SENT 10

int main() {
  int n;
  cin >> n;

  modded2[0] = SENT;
  modded2[1] = SENT;
  modded1[0] = SENT;
  modded1[1] = SENT;

  bool has_zero = false;

  int m2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> dig[i];

    if (dig[i] == 0) {
      has_zero = true;
    }

    m2 = (m2 + dig[i]) % 3;
    if (dig[i] % 3 == 2) {
      if (dig[i] < modded2[0]) {
        modded2[1] = modded2[0];
        modded2[0] = dig[i];
      } else if (dig[i] < modded2[1]) {
        modded2[1] = dig[i];
      }
    } else if (dig[i] % 3 == 1) {
      if (dig[i] < modded1[0]) {
        modded1[1] = modded1[0];
        modded1[0] = dig[i];
      } else if (dig[i] < modded1[1]) {
        modded1[1] = dig[i];
      }
    }
  }

  if (!has_zero) {
    cout << -1 << endl;
    return 0;
  }

  //cout << "MODDED1" << endl;
  //cout << modded1[0] << " " << modded1[1] << endl;
  //cout << "MODDED2" << endl;
  //cout << modded2[0] << " " << modded2[1] << endl;

  if (m2 == 0) {
  } else if (m2 == 1) {
    if (modded1[0] != SENT) {
      for (int i = 0; i < n; i++) {
        if (dig[i] == modded1[0]) {
          swap(dig[i], dig[n - 1]);
          n--;
          break;
        }
      }
    } else if (modded2[0] != SENT && modded2[1] != SENT) {
      for (int i = 0; i < n; i++) {
        if (dig[i] == modded2[0]) {
          swap(dig[i], dig[n - 1]);
          n--;
          break;
        }
      }
      for (int i = 0; i < n; i++) {
        if (dig[i] == modded2[1]) {
          swap(dig[i], dig[n - 1]);
          n--;
          break;
        }
      }
    } else {
      cout << -1 << endl;
      return 0;
    }
  } else {
    if (modded2[0] != SENT) {
      for (int i = 0; i < n; i++) {
        if (dig[i] == modded2[0]) {
          swap(dig[i], dig[n - 1]);
          n--;
          break;
        }
      }
    } else if (modded1[0] != SENT && modded1[1] != SENT) {
      for (int i = 0; i < n; i++) {
        if (dig[i] == modded1[0]) {
          swap(dig[i], dig[n - 1]);
          n--;
          break;
        }
      }
      for (int i = 0; i < n; i++) {
        if (dig[i] == modded1[1]) {
          swap(dig[i], dig[n - 1]);
          n--;
          break;
        }
      }
    } else {
      cout << -1 << endl;
      return 0;
    }
  }

  sort(dig, dig+n);
  reverse(dig, dig+n);

  if (dig[0] == 0) {
    cout << 0 << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cout << dig[i];
    }
    cout << endl;
  }
}

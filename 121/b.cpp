#include <iostream>

using namespace std;

char digs[100000];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> digs[i];
  }

  for (int i = 0; i < n - 1; i++) {
    if (k > 0) {
      if (digs[i] == '4' && digs[i + 1] == '7') {
        if (i % 2 == 0) {
          digs[i + 1] = '4';
          k--;
          continue;
        } else {
          if (i == 0) {
            digs[i] = '7';
            k--;
            continue;
          } else if (digs[i - 1] == '4') {
            if (k % 2 == 0) {
              k = 0;
              continue;
            } else {
              k = 0;
              digs[i] = '7';
              continue;
            }
          } else {
            digs[i] = '7';
            k--;
            continue;
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << digs[i];
  }
  cout << endl;
}

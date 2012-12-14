#include <iostream>
#include <string>

using namespace std;

string table[100];
int dpleft[100][10000];
int dpright[100][10000];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> table[i];
    bool all_zero = true;
    for (int j = 0; j < m; j++) {
      if (table[i][j] == '1') {
        all_zero = false;
      }
      dpleft[i][j] = -1;
      dpright[i][j] = -1;
    }

    if (all_zero) {
      cout << -1 << endl;
      return 0;
    }
  }

  int last = -1;
  for (int i = 0; i < n; i++) {
    last = -1;
    for (int A = 0; A < 2; A++) {
      for (int j = m - 1; j >= 0; j--) {
        if (table[i][j] == '1') {
          last = j;
        }
        if (dpright[i][j] == -1 && last != -1) {
          dpright[i][j] = (last >= j) ? last - j : last + (m - j);
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    last = -1;
    for (int A = 0; A < 2; A++) {
      for (int j = 0; j < m; j++) {
        if (table[i][j] == '1') {
          last = j;
        }
        if (dpleft[i][j] == -1 && last != -1) {
          dpleft[i][j] = (last <= j) ? j - last : (m - last) + j;
        }
      }
    }
  }

  int best = 100 * 10000;
  for (int j = 0; j < m; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += min(dpleft[i][j], dpright[i][j]);
    }
    //cout << j << ":" << sum << endl;
    best = min(sum, best);
  }
  cout << best << endl;

  //for (int x = 0; x < m; x++) {
    //cout << dpleft[1][x] << " ";
  //}
  //cout << endl;
  //for (int x = 0; x < m; x++) {
    //cout << dpright[1][x] << " ";
  //}
  //cout << endl;
}

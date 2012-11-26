#include <iostream>
#include <algorithm>

using namespace std;

int table[1000][1000];
int rows[1000];
int cols[1000];

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> table[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    rows[i] = i;
  }
  for (int i = 0; i < m; i++) {
    cols[i] = i;
  }

  char act;
  int a, b;
  for (int i = 0; i < k; i++) {
    cin >> act >> a >> b;
    a--;
    b--;
    if (act == 'g') {
      a = rows[a];
      b = cols[b];
      cout << table[a][b] << endl;
    } else if (act == 'r') {
      swap(rows[a], rows[b]);
    } else if (act == 'c') {
      swap(cols[a], cols[b]);
    }
  }
}

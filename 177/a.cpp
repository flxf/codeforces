#include <iostream>

using namespace std;

int mat[101][101];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += mat[i][i]; // main diag
    sum += mat[n/2][i]; // middle row
    sum += mat[i][n/2]; // middle col
    sum += mat[i][n - i - 1]; // 2nd diag
  }

  sum -= mat[n/2][n/2] * 3;
  cout << sum << endl;
}

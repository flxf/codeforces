#include <iostream>

using namespace std;

char w[100][100];
bool seen[26];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> w[i][j];
    }
  }

  unsigned long long soln = 1;

  for (int i = 0; i < m; i++) {
    for (int k = 0; k < 26; k++) {
      seen[k] = false;
    }

    for (int j = 0; j < n; j++) {
      seen[w[j][i] - 'A'] = true;
    }

    int sum = 0;
    for (int k = 0; k < 26; k++) {
      if (seen[k]) {
        sum++;
      }
    }

    soln = (soln * sum) % 1000000007;
  }

  cout << soln << endl;
}

#include <iostream>

using namespace std;

int a[100000];
int dp[100001];
bool dict[100001];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = n - 1; i >= 0; i--) {
    if (dict[a[i]]) {
      dp[i] = dp[i + 1];
    } else {
      dp[i] = dp[i + 1] + 1;
    }
    dict[a[i]] = true;
  }

  for (int i = 0; i < m; i++) {
    int l;
    cin >> l;
    cout << dp[l - 1] << endl;
  }
}

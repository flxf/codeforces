#include <iostream>

using namespace std;

int give[101];
int take[101];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    give[a] += c;
    take[b] += c;
  }

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int mn = min(give[i], take[i]);
    give[i] -= mn;
    take[i] -= mn;

    sum += give[i];
  }

  cout << sum << endl;
}

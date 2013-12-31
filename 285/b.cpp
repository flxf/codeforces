#include <iostream>

using namespace std;

int p[100000];
bool visited[100000];

int main() {
  int n, s, t;
  cin >> n >> s >> t;

  s--;
  t--;

  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }

  int cnt = 0;
  while (s != t) {
    if (visited[s]) {
      cout << -1 << endl;
      return 0;
    }

    visited[s] = true;
    s = p[s];
    cnt++;
  }

  cout << cnt << endl;
}

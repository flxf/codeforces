#include <iostream>
#include <vector>

using namespace std;

vector<int> G[100000];
bool visited[100000];
int deg[100000];

int connected(int x) {
  if (visited[x]) {
    return 0;
  }

  visited[x] = true;
  int ans = 1;
  for (int i = 0; i < G[x].size(); i++) {
    ans += connected(G[x][i]);
  }

  return ans;
}

int has_degree(int n, int k) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (G[i].size() == k) {
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int n, m;
  cin >> n >> m;

  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  if (n == m) { // check ring
    int conn = connected(0);
    int deg = has_degree(n, 2);
    if (conn == n && deg == n) {
      cout << "ring topology" << endl;
      return 0;
    }
  }

  if (n - 1 == m) {
    int conn = connected(0);
    int deg1 = has_degree(n, 1);
    int deg2 = has_degree(n, 2);
    int degC = has_degree(n, n - 1);

    if (conn == n) {
      if (deg1 == 2 && deg2 == n - 2) {
        cout << "bus topology" << endl;
        return 0;
      }

      if (deg1 == n - 1 && degC == 1) {
        cout << "star topology" << endl;
        return 0;
      }
    }
  }

  cout << "unknown topology" << endl;
}

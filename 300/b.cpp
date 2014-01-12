#include <iostream>
#include <vector>

using namespace std;

vector<int> G[50];
bool visited[50];
vector<int> groups[4];

int dfs(int x) {
  if (visited[x]) {
    return 0;
  }

  visited[x] = true;
  int ans = 1;
  for (int i = 0; i < G[x].size(); i++) {
    ans += dfs(G[x][i]);
  }
  return ans;
}

void print_dfs(int x) {
  if (visited[x]) {
    return;
  }

  visited[x] = true;
  cout << x << " ";
  for (int i = 0; i < G[x].size(); i++) {
    print_dfs(G[x][i]);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    int ret = dfs(i);
    if (ret > 3) {
      cout << -1 << endl;
      return 0;
    }

    groups[ret].push_back(i);
  }

  if (groups[1].size() < groups[2].size()) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < 50; i++) {
    visited[i] = false;
  }

  for (int i = 0; i < groups[3].size(); i++) {
    print_dfs(groups[3][i]);
    cout << endl;
  }

  for (int i = 0; i < groups[2].size(); i++) {
    print_dfs(groups[2][i]);
    print_dfs(groups[1][i]);
    cout << endl;
  }

  for (int i = groups[2].size(); i < groups[1].size(); i += 3) {
    print_dfs(groups[1][i]);
    print_dfs(groups[1][i + 1]);
    print_dfs(groups[1][i + 2]);
    cout << endl;
  }
}

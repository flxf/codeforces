#include <vector>
#include <utility>
#include <iostream>

using namespace std;

#define ITV pair<int, int>

vector<int> G[101];
bool visited[101];
vector<ITV > itvs;

bool connects(ITV a, ITV b) {
  return (b.first < a.first && a.first < b.second) || (b.first < a.second && a.second < b.second);
}

bool dfs(int curr, int dest) {
  if (curr == dest) {
    return true;
  }

  visited[curr] = true;

  bool res = false;
  for (int i = 0; i < G[curr].size(); i++) {
    int neighbour = G[curr][i];
    if (!visited[neighbour]) {
      res |= dfs(neighbour, dest);
    }
  }

  return res;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int o, a, b;
    cin >> o >> a >> b;

    if (o == 1) {
      int new_i = itvs.size();
      itvs.push_back(make_pair(a, b));

      for (int i = 0; i < itvs.size() - 1; i++) {
        if (connects(itvs[i], itvs[new_i])) {
          G[i].push_back(new_i);
        }
        if (connects(itvs[new_i], itvs[i])) {
          G[new_i].push_back(i);
        }
      }
    } else {
      fill(visited, visited+101, false);
      a--;
      b--;

      if (dfs(a, b)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}

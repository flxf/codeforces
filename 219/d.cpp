#include <iostream>
#include <vector>
#include <cmath>
#include <deque>

using namespace std;

vector<int> G[200001];
bool visited[200001];
int cost[200001];

bool has_visited(int n) {
  n = (n < 0) ? n * -1 : n;
  return visited[n];
}

int rec(int n) {
  visited[n] = true;

  int cost = 0;
  for (int i = 0; i < G[n].size(); i++) {
    if (!has_visited(G[n][i])) {
      if (G[n][i] < 0) {
        cost++;
      }
      cost += rec(abs(G[n][i]));
    }
  }

  return cost;
}

int main() {
  int n;
  cin >> n;

  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(-1 * a);
  }

  int start = -1;
  for (int i = 1; i <= n; i++) {
    if (G[i].size() == 1) {
      start = i;
      break;
    }
  }

  cost[start] = rec(start);

  // resetting
  for (int i = 0; i <= n; i++) {
    visited[i] = false;
  }

  deque<int> it;
  it.push_back(abs(G[start][0]));
  visited[start] = true;

  while (!it.empty()) {
    int solve = it.front();
    it.pop_front();
    visited[solve] = true;

    for (int i = 0; i < G[solve].size(); i++) {
      int neighbour = G[solve][i];
      int an = (neighbour < 0) ? neighbour * -1 : neighbour;

      if (has_visited(neighbour)) {
        if (neighbour < 0) {
          cost[solve] = cost[an] + 1;
        } else {
          cost[solve] = cost[an] - 1;
        }
      } else {
        it.push_back(abs(neighbour));
      }
    }
  }

  int best = cost[1];
  for (int i = 2; i <= n; i++) {
    if (cost[i] < best) {
      best = cost[i];
    }
  }

  cout << best << endl;
  for (int i = 1; i <= n; i++) {
    if (cost[i] == best) {
      cout << i << " ";
    }
  }
  cout << endl;
}

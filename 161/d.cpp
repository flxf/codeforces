#include <iostream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

vector<int> G[50000];
int visited[50000];
int n, k, time;

unsigned long long CNT = 0;

void bfs(int x) {
  visited[x] = time;

  deque<pair<int, int> > q;
  q.push_back(make_pair(0, x));
  pair<int, int> p;

  while (!q.empty()) {
    p = q.front();
    q.pop_front();

    int curr = p.second;
    int dist = p.first;

    for (int i = 0; i < G[curr].size(); i++) {
      if (visited[G[curr][i]] != time) {
        visited[G[curr][i]] = time;
        if (dist == k - 1) {
          CNT++;
        } else {
          q.push_back(make_pair(dist + 1, G[curr][i]));
        }
      }
    }
  }
}

int main() {
  cin >> n >> k;

  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  time = 1;
  for (int i = 0; i < n; i++) {
    bfs(i);
    time++;
  }

  cout << CNT / 2 << endl;
}

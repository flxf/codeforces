#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

vector<int> G[200001];
map<pair<int, int>, int > memo;
int visited[200001];
int ITER = 0;

int rec(int from, int ignore) {
  visited[from] = ITER;

  pair<int, int> p = make_pair(from, ignore);
  if (memo.find(p) != memo.end()) {
    return memo[p];
  }

  int sum = 0;
  for (int i = 0; i < G[from].size(); i++) {
    int to = G[from][i];
    int ato = abs(to);
    if (ato != ignore && visited[ato] != ITER) {
      if (to < 0) {
        sum += 1 + rec(ato, from);
      } else {
        sum += rec(ato, from);
      }
    }
  }

  memo[make_pair(from, ignore)] = sum;
  return sum;
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

  int best = n - 1;
  vector<int> sols;
  for (ITER = 1; ITER <= n; ITER++) {
    int thusly = rec(ITER, 0);
    if (thusly == best) {
      sols.push_back(ITER);
    } else if (thusly < best) {
      sols.clear();
      sols.push_back(ITER);
      best = thusly;
    }
  }

  cout << best << endl;
  for (int i = 0; i < sols.size(); i++) {
    cout << sols[i] << " ";
  }
  cout << endl;
}

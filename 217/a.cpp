#include <iostream>
#include <utility>

using namespace std;

pair<int, int> p[1000];
int parents[1000];
bool xes[1000][1001];
bool yes[1000][1001];
bool seen[1000];

bool meet(int u, int v) {
  for (int a = 1; a <= 1000; a++) {
    if (xes[u][a] && xes[v][a]) {
      return true;
    }
    if (yes[u][a] && yes[v][a]) {
      return true;
    }
  }
  return false;
}

int get_parent(int v) {
  if (parents[v] == v) {
    return v;
  }
  parents[v] = get_parent(parents[v]);
  return parents[v];
}

void set_parent(int u, int v) {
  int r = get_parent(u);
  int p = get_parent(v);
  //cout << "r: " << r << " p:" << p << endl;
  parents[r] = p;

  for (int a = 1; a <= 1000; a++) {
    xes[p][a] |= xes[r][a];
    yes[p][a] |= yes[r][a];
  }
}

int main() {
  int n;
  cin >> n;

  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    p[i] = make_pair(x, y);
    parents[i] = i;
    xes[i][x] = true;
    yes[i][y] = true;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      int u = get_parent(i);
      int v = get_parent(j);
      if (meet(u, v)) {
        //cout << "MEETED" << endl;
        set_parent(u, v);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    //cout << ":" << get_parent(i) << endl;
    seen[get_parent(i)] = true;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (seen[i]) {
      cnt++;
    }
  }

  //cout << cnt << endl;
  cout << cnt - 1 << endl;
}

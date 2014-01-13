#include <iostream>
#include <vector>

using namespace std;

int types[100000];
vector<int>G[100001];
int dist[100001];

int dfs(int x) {
  if (dist[x] != -2) {
    return dist[x];
  }
  if (types[x] == 1) {
    return 1;
  }
  if (G[x].size() > 1 || G[x].size() == 0) {
    return -1;
  }

  // cycle prevention
  dist[x] = -1;
  int further = dfs(G[x][0]);
  if (further == -1) {
    dist[x] = -1;
  } else {
    dist[x] = further + 1;
  }
  return dist[x];
}

void printdfs(int x) {
  cout << x + 1 << " ";
  if (types[x] == 1) {
    return;
  }
  printdfs(G[x][0]);
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> types[i];
  }
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a != 0) {
      G[a - 1].push_back(i);
    }
    dist[i] = -2;
  }

  int maxi = 0;
  int mx = dfs(0);
  for (int i = 1; i < n; i++) {
    int val = dfs(i);
    if (val > mx) {
      mx = val;
      maxi = i;
    }
  }

  cout << mx << endl;
  printdfs(maxi);
  cout << endl;
}

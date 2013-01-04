#include <iostream>
#include <vector>

using namespace std;

vector<int> G[100];
bool visited[100];

int cyc_size = 0;

bool rec(int i, int last) {
  if (visited[i]) {
    return true;
  }

  visited[i] = true;
  cyc_size++;
  bool ans = false;
  for (int j = 0; j < G[i].size(); j++) {
    if (G[i][j] != last) {
      ans |= rec(G[i][j], i);
    }
  }
  return ans;
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

  int cyc = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      cyc_size = 0;
      if (rec(i, -1) && cyc_size % 2 == 1) {
        cyc++;
      }
    }
  }

  if (cyc % 2 == n % 2) {
    cout << cyc << endl;
  } else {
    cout << cyc + 1 << endl;
  }
}

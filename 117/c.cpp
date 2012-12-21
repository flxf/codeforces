#include <iostream>
#include <vector>

using namespace std;

int n;
char A[5000][5000];
vector<int> G[5000];
bool visited[5000];
int seen[5000];

int cycle[5000];
int cyclelen = 0;
int cyclestart = 0;

bool rec(int pos, int x) {
  //cout << pos << ":" << x << endl;
  if (seen[pos] != -1) {
    //cout << "VISITED" << endl;
    cyclelen = x;
    cyclestart = seen[pos];
    return true;
  }
  if (visited[pos]) {
    return false;
  }

  seen[pos] = x;
  visited[pos] = true;
  cycle[x] = pos;

  for (int i = 0; i < G[pos].size(); i++) {
    if (seen[G[pos][i]] != -1 || !visited[G[pos][i]]) {
      if (rec(G[pos][i], x+1)) {
        return true;
      }
    }
  }

  //for (int i = 0; i < n; i++) {
    //if (A[pos][i] == '1') {
      //if (seen[i] != -1 || !visited[i]) {
        //if (rec(i, x+1)) {
          //return true;
        //}
      //}
    //}
  //}

  seen[pos] = -1;
  return false;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
      if (A[i][j] == '1') {
        G[i].push_back(j);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    seen[i] = -1;
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      if (rec(i, 0)) {
        break;
      }
    }
  }

  if (cyclelen > 0) {
    int first = cycle[cyclestart];
    int slast;

    while (true) {
      slast = cycle[cyclelen - 2];
      if (A[first][slast] == '1') {
        cout << (first+1) << " " << (slast+1) << " " << (cycle[cyclelen - 1]+1) << endl;
        break;
      }
      cyclelen--;
    }
  } else {
    cout << -1 << endl;
  }
}

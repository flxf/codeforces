#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define WE pair<int, int>

vector<WE > G[100000];
priority_queue<WE, vector<WE >, greater<WE > > q;

int shortests[100000];
int count = 0;

int main() {
  int n, m, s;
  cin >> n >> m >> s;

  s--;

  int v, u, w;
  for (int i = 0; i < m; i++) {
    cin >> v >> u >> w;
    v--;
    u--;
    G[v].push_back(make_pair(w, u));
    G[u].push_back(make_pair(w, v));
  }

  int l;
  cin >> l;

  for (int i = 0; i < n; i++) {
    shortests[i] = -1;
  }

  WE curr;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    curr = q.top();
    int weight = curr.first;
    int pos = curr.second;
    q.pop();

    //cout << pos << ":" << weight << endl;
    if (shortests[pos] != -1) {
      continue;
    }
    shortests[pos] = weight;

    if (weight == l) {
      //cout << pos << "AA" << endl;
      count++;
    }

    for (int i = 0; i < G[pos].size(); i++) {
      WE conn = G[pos][i];
      q.push(make_pair(weight + conn.first, conn.second));
    }
  }

  //for (int i = 0; i < n; i++) {
    //cout << i << "->" << shortests[i] << endl;
  //}

  //int secondcount = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < G[i].size(); j++) {
      int ew = G[i][j].first;
      int shorta = shortests[i];
      int shortb = shortests[G[i][j].second];
      if (shorta < shortb) {
        if (shorta < l && shorta + ew > l) {
          //cout << "AA" << endl;
          //cout << i << ":" << G[i][j].second << ":" << shorta << endl;
          count++;
        }
      } else if (shorta == shortb && i < G[i][j].second) {
        if (shorta < l && shorta + ew > l) {
          //cout << "CC" << endl;
          //cout << i << ":" << G[i][j].second << ":" << shorta << endl;
          count++;
          if ((l - shorta) * 2 < ew) {
            //cout << "DD" << endl;
            count++;
          }
        }
      } else if (shorta > shortb) {
        if (shorta < l && shorta + ew > l && (ew - (l - shorta) - (l - shortb)) > 0) {
          //cout << "BB" << endl;
          //cout << i << ":" << G[i][j].second << ":" << shorta << endl;
          count++;
        }
      }
    }
  }

  cout << count << endl;
}

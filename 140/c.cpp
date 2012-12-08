#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

map<int, int> m;
int balls[100000];
int output[100000][3];
vector<pair<int, int> > p;

int med(int a, int b, int c) {
  int biggest = max(a, max(b, c));
  int smallest = min(a, min(b, c));
  if (a != biggest && a != smallest) {
    return a;
  }
  if (b != biggest && b != smallest) {
    return b;
  }
  return c;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> balls[i];
    if (m.find(balls[i]) != m.end()) {
      m[balls[i]]++;
    } else {
      m[balls[i]] = 1;
    }
  }

  priority_queue<pair<int, int> > pq;
  for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
    pq.push(make_pair(it->second, it->first));
  }

  pair<int, int> a, b, c;
  int cnt = 0;
  int d;
  while (pq.size() >= 3) {
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();
    c = pq.top();
    pq.pop();

    if (pq.size() >= 1) {
      d = pq.top().first;
    } else {
      d = 1;
    }

    int x = c.first - d + 1;
    //cout << "FEL" << x << ":" << b.first << ":" << a.first << endl;
    for (int i = 0; i < x; i++) {
      output[cnt][0] = max(a.second, max(b.second, c.second));
      output[cnt][1] = med(a.second, b.second, c.second);
      output[cnt][2] = min(a.second, min(b.second, c.second));
      cnt++;
    }

    if (a.first - x > 0) {
      pq.push(make_pair(a.first - x, a.second));
    }
    if (b.first - x > 0) {
      pq.push(make_pair(b.first - x, b.second));
    }
    if (c.first - x > 0) {
      pq.push(make_pair(c.first - x, c.second));
    }
  }

  cout << cnt << endl;
  for (int i = 0; i < cnt; i++) {
    cout << output[i][0] << " " << output[i][1] << " " << output[i][2] << endl;
  }
}

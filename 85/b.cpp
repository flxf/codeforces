#include <queue>
#include <iostream>
#include <functional>
#include <vector>
#include <utility>

using namespace std;

#define ull unsigned long long
#define P pair<ull, ull>

int main() {
  priority_queue<P, vector<P >, greater<P > > q[4];

  int k[4];
  cin >> k[1] >> k[2] >> k[3];

  int t[4];
  cin >> t[1] >> t[2] >> t[3];

  int w[4];
  w[0] = 0;
  w[1] = 0;
  w[2] = 0;
  w[3] = 0;

  int n;
  cin >> n;

  ull c;
  ull last_start = 0;
  for (int i = 0; i < n; i++) {
    cin >> c;
    last_start = max(last_start, c);
    q[0].push(make_pair(c, c));
  }

  ull latest = 0;

  //int cnt = 0;
  while (true) {
    int best = -1;
    for (int i = 3; i >= 0; i--) {
      if (q[i].size() > 0) {
        if (best == -1 || q[i].top().first < q[best].top().first) {
          best = i;
        }
      }
    }

    //cnt ++;
    if (best == -1) {
      break;
    }

    ull next_time = q[best].top().first;
    ull start_time = q[best].top().second;
    //cout << best << ":" << next_time << ":" << start_time << endl;
    q[best].pop();

    if (w[best] > 0) {
      //cout << "A" << endl;
      q[best].push(make_pair(next_time + t[best], start_time));
      w[best]--;
    } else {
      //cout << "B" << endl;
      k[best]++;
    }

    int next_w = best + 1;
    if (next_w < 4) {
      if (k[next_w] > 0) {
        //cout << "C" << endl;
        k[next_w]--;
        q[next_w].push(make_pair(next_time + t[next_w], start_time));
      } else {
        //cout << "D" << endl;
        w[next_w]++;
      }
    } else {
      if (next_time > last_start) {
        latest = max(latest, next_time - last_start);
      }
    }
  }

  cout << latest << endl;
}

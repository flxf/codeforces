#include <iostream>
#include <algorithm>

using namespace std;

#define X first.first
#define T first.second
#define I second

pair<pair<int, int>, int> student[100000];
int ans[100000];

int main() {
  int n, m;
  cin >> n >> m;

  int x, t;
  for (int i = 0; i < n; i++) {
    cin >> t >> x;
    student[i] = make_pair(make_pair(x, t), i);
  }

  for (int i = 0; i <= (n - 1) / m; i++) {
    sort(student + i * m, min(student + i * m + m, student + n));
  }

  int tot = 0;
  for (int i = 0; i <= (n - 1) / m; i++) {
    int lastx = 0;
    int lastcnt = 0;
    int maxx = 0;
    int maxt = tot;
    int getoff = 0;

    for (int j = 0; j < m; j++) {
      int p = i * m + j;
      if (p >= n) {
        break;
      }
      maxt = max(maxt, student[p].T);
    }
    //cout << "::" << maxt << endl;

    for (int j = 0; j < m; j++) {
      int p = i * m + j;
      if (p >= n) {
        break;
      }

      if (student[p].X != lastx) {
        if (lastcnt > 0) {
          getoff += (lastcnt / 2) + 1;
        }
        lastx = student[p].X;
        lastcnt = 1;
      } else {
        lastcnt++;
      }

      maxx = max(maxx, student[p].X);
      //cout << student[p].I << " = " << maxt << "+" << getoff << "+" << student[p].X << endl;
      ans[student[p].I] = maxt + getoff + student[p].X;
    }

    getoff += (lastcnt / 2) + 1;
    tot = maxt + getoff + maxx * 2;
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

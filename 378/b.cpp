#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

bool semi[2][100000];
pair<int, pair<int, int> > all[200000];

#define score first
#define clazz second.first
#define ind second.second

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    all[i] = make_pair(a, make_pair(0, i));
    all[n + i] = make_pair(b, make_pair(1, i));
  }
  sort(all, all + 2 * n);

  for (int i = 0; i < n; i++) {
    semi[all[i].clazz][all[i].ind] = true;
  }

  for (int i = 0; i < n / 2; i++) {
    semi[0][i] = true;
    semi[1][i] = true;
  }

  for (int a = 0; a < 2; a++) {
    for (int i = 0; i < n; i++) {
      if (semi[a][i]) {
        cout << 1;
      } else {
        cout << 0;
      }
    }
    cout << endl;
  }
}

#include <iostream>

using namespace std;

#define RED 1
#define BLUE 2
#define GREEN 3

int color[100001];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    int prev = (color[a] + color[b] + color[c]);
    if (prev == 0) {
      color[a] = RED;
      color[b] = BLUE;
      color[c] = GREEN;
    } else {
      int l, r;
      if (prev == RED) {
        l = BLUE;
        r = GREEN;
      } else if (prev == BLUE) {
        l = RED;
        r = GREEN;
      } else {
        l = RED;
        r = BLUE;
      }

      if (color[a] != 0) {
        color[b] = l;
        color[c] = r;
      } else if (color[b] != 0) {
        color[a] = l;
        color[c] = r;
      } else if (color[c] != 0) {
        color[a] = l;
        color[b] = r;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << color[i] << " ";
  }
  cout << endl;
}

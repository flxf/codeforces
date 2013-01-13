#include <iostream>

using namespace std;

int how(int v) {
  if (v == 0) {
    return 0;
  }
  if (v % 10 == 4 || v % 10 == 7) {
    return 1 + how(v / 10);
  }
  return how(v / 10);
}

int main() {
  int n, k;
  cin >> n >> k;

  int v;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> v;
    int hw = how(v);
    if (hw <= k) {
      cnt++;
    }
  }

  cout << cnt << endl;
}

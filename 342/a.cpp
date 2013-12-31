#include <iostream>

using namespace std;

int cnt[10];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }

  if ((cnt[1] != n / 3)
      || (cnt[2] + cnt[3] != n / 3)
      || (cnt[4] + cnt[6] != n / 3)) {
    cout << -1 << endl;
    return 0;
  }

  if (cnt[2] < cnt[4]) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < cnt[4]; i++) {
    cout << "1 2 4" << endl;
  }
  cnt[2] -= cnt[4];

  for (int i = 0; i < cnt[2]; i++) {
    cout << "1 2 6" << endl;
  }
  for (int i = 0; i < cnt[3]; i++) {
    cout << "1 3 6" << endl;
  }
}

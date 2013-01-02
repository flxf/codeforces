#include <iostream>

using namespace std;

int main() {
  unsigned long long w, h;
  cin >> w >> h;

  unsigned long long cnt = 0;
  for (unsigned long long a = 2; a <= w; a += 2) {
    for (unsigned long long b = 2; b <= h; b += 2) {
      cnt += (w - a + 1) * (h - b + 1);
    }
  }

  cout << cnt << endl;
}

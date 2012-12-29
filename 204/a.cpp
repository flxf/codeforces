#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long

int main() {
  ull l, r;
  cin >> l >> r;

  ull cnt = 0;
  for (int i = 1; i <= 9; i++) {
    if (i >= l && i <= r) {
      cnt++;
    }
  }

  ull pow = 1;
  for (int i = 1; i <= 18; i++) {
    pow *= 10;
    for (int j = 1; j <= 9; j++) {
      ull bot = j * pow + j;
      ull top = j * pow + (pow - 10) + j;

      // no intersection
      if (l > top || r < bot) {
        continue;
      }

      if (bot >= l && top <= r) { // contained
        cnt += pow / 10;
      } else if (l >= bot && r <= top) { // other contained
      }

      //cout << bot << " to " << top << endl;
    }
  }

}

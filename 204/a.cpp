// Read another editorial. Today is a learning day.

#include <iostream>

#define ull unsigned long long

using namespace std;

ull logten(ull x) {
  if (x < 10) {
    return 0;
  }
  return 1 + logten(x / 10);
}

ull pow(ull x, ull k) {
  if (k == 0) {
    return 1;
  }
  return x * pow(x, k - 1);
}

ull F(ull x) {
  if (x < 10) {
    return x;
  }

  ull lg = logten(x);
  ull digs = lg + 1;
  ull up = pow(10, lg);
  ull firstdigit = x / up;
  ull lastdigit = x % 10;
  ull xp = (x - ((x / up) * up)) / 10;

  ull ans = 0;

  for (int i = 1; i <= digs; i++) {
    for (int d = 1; d <= 9; d++) {
      if (i == digs && d == firstdigit) {
        ans += xp;
        if (lastdigit >= d) {
          ans += 1;
        }
      } else if (i == digs && d < firstdigit) {
        ans += pow(10, i - 2);
      } else if (i < digs) {
        if (i == 1) {
          ans++;
        } else {
          ans += pow(10, i - 2);
        }
      }
    }
  }

  return ans;
}

int main() {
  ull l, r;
  cin >> l >> r;

  cout << F(r) - F(l - 1) << endl;
}

#include <iostream>
#include <cmath>

using namespace std;

#define ULL unsigned long long

int main() {
  int n;
  cin >> n;

  ULL mx = 0, mn = 0;
  for (ULL b = 1; b <= sqrt(n); b++) {
    for (ULL c = b; ; c++) {
      ULL a = n / (b * c);
      if (a < c) {
        break;
      }
      if (n % (b * c) == 0) {
        //cout << ":" << b << ":" << c << ":" << a << endl;
        if (mx == 0) {
          mx = (a + 1) * (b + 2) * (c + 2);
          mn = (a + 1) * (b + 2) * (c + 2);
        }
        mx = max(mx, (a + 1) * (b + 2) * (c + 2));
        mx = max(mx, (a + 2) * (b + 1) * (c + 2));
        mx = max(mx, (a + 2) * (b + 2) * (c + 1));
        mn = min(mn, (a + 1) * (b + 2) * (c + 2));
        mn = min(mn, (a + 2) * (b + 1) * (c + 2));
        mn = min(mn, (a + 2) * (b + 2) * (c + 1));
      }
    }
  }

  cout << mn - n << " " << mx - n << endl;
}

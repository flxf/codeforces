#include <iostream>
#include <set>
#define ULL unsigned long long

using namespace std;

ULL sum(ULL n) {
  int c = 0;
  while (n != 0) {
    c += n % 10;
    n /= 10;
  }
  return c;
}

int main() {
  // binary search on the sqrts, not perfect!
  ULL lo = 0;
  ULL hi = 1000000000ULL;

  ULL n;
  cin >> n;

  ULL val = 0;
  while (lo <= hi) {
    ULL mid = (lo + hi) / 2;
    ULL test = mid*mid;
    //cout << mid << ":" << test << endl;
    if (n == test) {
      val = mid;
      break;
    } else if (test > n) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  if (val == 0) {
    val = hi;
  }

  ULL beg = 0;
  if (val > 1000000ULL) {
    beg = val - 1000000ULL;
  }

  //cout << val << ":" << max(0ULL, val - 10000000ULL) << endl;
  for (ULL i = beg; i <= val; i++) {
    ULL test = i*i + sum(i)*i;
    //cout << i << ":" << test << endl;
    if (test == n) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;


}

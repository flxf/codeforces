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

  while (lo <= hi) {
    ULL mid = (lo + hi) / 2;
    ULL test = mid*mid + sum(mid) * mid;
    cout << mid << ":" << test << endl;
    if (n == test) {
      cout << mid << endl;
      return 0;
    } else if (test > n) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << -1 << endl;
}

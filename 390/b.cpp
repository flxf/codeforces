#include <iostream>

using namespace std;

#define ULL long long

ULL a[100000];
ULL b[100000];

ULL best(ULL ai, ULL bi) {
  if (2 * ai < bi || bi < 2) {
    return -1;
  }

  ULL half = bi / 2;

  if (bi % 2 == 0) {
    return half * half;
  }
  return half * (half + 1);
}

int main() {
  ULL n;
  cin >> n;

  for (ULL i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (ULL i = 0; i < n; i++) {
    cin >> b[i];
  }

  ULL joy = 0;
  for (ULL i = 0; i < n; i++) {
    joy += best(a[i], b[i]);
  }

  cout << joy << endl;

  return 0;
}

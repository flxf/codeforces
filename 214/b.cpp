#include <iostream>
#include <algorithm>

using namespace std;

int dig[100000];

int main() {
  int n;
  cin >> n;

  int m2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> dig[i];
    m2 = (m2 + dig[i]) % 3;
  }
  sort(dig, dig+n);

  if (m2 == 0) {
  } else if (m2 == 1) {
  } else {
  }
}

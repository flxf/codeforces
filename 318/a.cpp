#include <iostream>

using namespace std;

int main() {
  unsigned long long n, k;
  cin >> n >> k;

  k--;

  unsigned long long fh = 0;
  if (n % 2 == 0) {
    fh = n / 2; 
  } else {
    fh = n / 2 + 1;
  }

  if (k < fh) {
    cout << k * 2 + 1 << endl;
  } else {
    k -= fh;
    cout << k * 2 + 2 << endl;
  }
}

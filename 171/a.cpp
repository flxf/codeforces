#include <iostream>

#define ULL unsigned long long

using namespace std;

ULL rev(int n) {
  ULL ans = 0;
  while (n != 0) {
    ans *= 10;
    ans += n % 10;
    n /= 10;
  }
  return ans;
}

int main() {
  int a, b;
  cin >> a >> b;

  cout << a + rev(b) << endl;
}

#include <iostream>

using namespace std;

int main() {
  int p;
  cin >> p;

  int ans = 0;

  for (int x = 1; x < p; x++) {
    int pow = 1;
    bool divisible = false;
    for (int s = 1; s <= p - 2; s++) {
      pow = (x * pow) % p;

      if (pow == 1) {
        divisible = true;
      }
    }

    if (!divisible) {
      pow = (x * pow) % p;
      if (pow == 1) {
        ans++;
        //cout << x << " is a primitive root" << endl;
      }
    }
  }

  cout << ans << endl;
}

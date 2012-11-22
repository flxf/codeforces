#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n % 2 == 1) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cout << ((i / 2) + 1) * 2 - (i % 2) << " ";
    }
    cout << endl;
  }
}

#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
  } else if (n == 2) {
    cout << "2 1" << endl;
  } else {
    cout << n;
    for (int i = 1; i < n; i++) {
      cout << " " << i;
    }
    cout << endl;
  }
}

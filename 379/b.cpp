#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    for (int j = 0; j < a; j++) {
      cout << "P";
      if (i == n - 1) {
        cout << "LR";
      } else {
        cout << "RL";
      }
    }

    if (i != n - 1) {
      cout << "R";
    }
  }
  cout << endl;
}

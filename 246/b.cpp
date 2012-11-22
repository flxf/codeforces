#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    sum += a;
  }

  if (sum % n == 0) {
    cout << n << endl;
  } else {
    cout << n - 1 << endl;
  }
}

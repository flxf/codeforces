#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  k = k - 2*n;
  cout << max(n - k, 0) << endl;
}

#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= 2 * n; i++) {
    a[i - 1] = i;
  }
  for (int i = 0; i < k; i++) {
    swap(a[i * 2], a[i * 2 + 1]);
  }

  for (int i = 0; i < 2 * n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

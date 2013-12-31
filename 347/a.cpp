#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int x[100];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x+n);
  swap(x[0], x[n-1]);

  for (int i = 0; i < n; i++) {
    cout << x[i] << " ";
  }
  cout << endl;
}

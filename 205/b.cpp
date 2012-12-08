#include <iostream>

using namespace std;

int a[100000];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  unsigned long long tot = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      tot += (a[i - 1] - a[i]);
      //cout << a[i - 1] - a[i] << endl;
    }
  }

  cout << tot << endl;
}

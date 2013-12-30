#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int a[300000];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);

  unsigned long long difference = 0;
  for (int i = 0; i < n; i++) {
    difference += abs((i + 1) - a[i]);
  }

  cout << difference << endl;
}

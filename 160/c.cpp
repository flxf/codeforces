#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a,a+n);

  k--;
  int first = k / n;
  int second = k % n;
  cout << a[first] << " " << a[second] << endl;
}

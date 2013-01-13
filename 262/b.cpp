#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];

int main() {
  int n, k;
  cin >> n >> k;

  int neg = 0;
  int smallest = 200000;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    smallest = min(smallest, abs(a[i]));
    if (a[i] < 0) {
      neg++;
    }
  }
  sort(a, a+n);

  for (int i = 0; i < min(k, neg); i++) {
    a[i] = a[i] * -1;
  }

  int extra = (k > neg) ? k - neg : 0;
  long long sum = 0;
  if (extra % 2 == 1) {
    sum -= smallest * 2;
  }

  for (int i = 0; i < n; i++) {
    sum += a[i];
  }

  cout << sum << endl;
}

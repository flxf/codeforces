#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long a[2000000];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);

  vector<long long> pows;
  pows.push_back(1);

  long long p = 4;
  while (p <= n) {
    pows.push_back(p);
    p *= 4;
  }
  
  int iter = 0;
  long long mult = pows.size();
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    if (i >= pows[iter]) {
      iter++;
      mult--;
    }

    sum += mult * a[n - i - 1];
  }

  cout << sum << endl;
}

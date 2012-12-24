#include <iostream>
#include <vector>

using namespace std;

int t[20000];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  vector<int> divisors;
  for (int i = 3; i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
    }
  }

  int bestsum = 20000 * -1000;
  for (int i = 0; i < divisors.size(); i++) {
    for (int j = 0; j < n / divisors[i]; j++) {
      int sum = 0;
      for (int k = j; k < n; k += n / divisors[i]) {
        sum += t[k];
      }
      bestsum = max(bestsum, sum);
      //cout << sum << endl;
    }
  }

  cout << bestsum << endl;
}

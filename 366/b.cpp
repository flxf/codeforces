#include <iostream>

using namespace std;

int a[100000];

int main() {
  int n, k;
  cin >> n >> k;

  int best = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    best += a[i];
  }
  best += 1;

  int besti;
  for (int i = 0; i < k; i++) {
    int sum = 0;
    for (int j = i; j < n; j += k) {
      sum += a[j];
    }

    if (sum < best) {
      besti = i;
      best = sum;
    }
  }

  cout << besti + 1 << endl;
}

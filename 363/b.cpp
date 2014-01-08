#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int plank[150000];
  for (int i = 0; i < n; i++) {
    cin >> plank[i];
  }

  int best = 0;
  int besti = 0;
  for (int i = 0; i < k; i++) {
    best += plank[i];
  }

  int sum = best;
  for (int i = k; i < n; i++) {
    sum += plank[i];
    sum -= plank[i - k];

    if (sum < best) {
      best = sum;
      besti = i - k + 1;
    }
  }

  cout << besti + 1 << endl;
}

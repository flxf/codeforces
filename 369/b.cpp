#include <iostream>

using namespace std;

int main() {
  int n, k, l, r, sall, sk;
  cin >> n >> k >> l >> r >> sall >> sk;

  if (k > 0) {
    for (int i = 0; i < k; i++) {
      int score = sk / k;
      if (sk % k > i) {
        score++;
      }
      cout << score << " ";
    }
  }

  int rem = n - k;
  if (rem > 0) {
    int srem = sall - sk;
    for (int i = 0; i < rem; i++) {
      int score = srem / rem;
      if (srem % rem > i) {
        score++;
      }
      cout << score << " ";
    }
  }

  cout << endl;
}

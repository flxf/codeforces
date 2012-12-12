#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define SQ 25000000
#define SQR 5000

bool is_prime[SQ+1];

int main() {
  int a, b, k;
  cin >> a >> b >> k;

  memset(is_prime, 1, SQ+1);
  is_prime[0] = false;
  is_prime[1] = false;

  for (int i = 2; i <= SQR; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= SQ; j += i) {
        is_prime[j] = false;
      }
    }
  }

  vector<int> p;
  for (int i = 0; i <= SQ; i++) {
    if (is_prime[i]) {
      p.push_back(i);
    }
  }

  int l = -1;
  int maybe;
  int d = 0;
  for (int i = a; i <= b; i++) {
    maybe = b - i + 1;
    int idx = lower_bound(p.begin(), p.end(), i) - p.begin();
    int kn = idx + k - 1;
    d = max(d, p[kn] - i);

    if (d < maybe) {
      l = maybe;
      //cout << "GOOD" << endl;
    } else {
      break;
    }
  }

  cout << l << endl;
}

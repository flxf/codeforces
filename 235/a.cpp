#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000001
#define SQRT 1001
#define ull unsigned long long

bool isprime[MAX];

ull gcd(ull a, ull b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

ull lcm(ull a, ull b) {
  return a * b / gcd(a, b);
}

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  for (int i = 0; i < MAX; i++) {
    isprime[i] = true;
  }
  isprime[0] = false;
  isprime[1] = false;

  for (int i = 2; i < SQRT; i++) {
    for (int j = i*i; j <= n; j += i) {
      isprime[j] = false;
    }
  }

  vector<int> primes;

  for (int i = 0; i <= n; i++) {
    if (isprime[i]) {
      primes.push_back(i);
    }
  }

  ull a, b, c;
  a = primes[max((int)(primes.size() - 1), 0)];
  b = primes[max((int)(primes.size() - 2), 0)];
  c = primes[max((int)(primes.size() - 3), 0)];

  ull best_lcm = lcm(a, lcm(b, c));

  for (int i = a; i <= n; i++) {
    for (int j = b; j <= n; j++) {
      for (int k = c; k <= n; k++) {
        ull now = lcm(i, lcm(j, k));
        if (now > best_lcm) {
          best_lcm = now;
        }
      }
    }
  }

  cout << best_lcm << endl;
}

#include <iostream>
#include <vector>

using namespace std;

#define SQRT 32000
#define SQ2 180
#define ull unsigned long long

bool isprime[SQRT];

int main() {
  int n;
  cin >> n;

  for (int i = 2; i < SQRT; i++) {
    isprime[i] = true;
  }
  for (int i = 2; i < SQ2; i++) {
    if (isprime[i]) {
      for (int j = i*i; j < SQRT; j += i) {
        isprime[j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 2; i < SQRT; i++) {
    if (isprime[i]) {
      primes.push_back(i);
    }
  }

  vector<int> divisors;
  for (int i = 0; i < primes.size(); i++) {
    while (n % primes[i] == 0) {
      divisors.push_back(primes[i]);
      n /= primes[i];
    }
  }

  if (n > 1) {
    divisors.push_back(n);
  }

  ull sum = 0;
  for (int i = 0; i <= divisors.size(); i++) {
    ull val = 1;
    for (int j = i; j < divisors.size(); j++) {
      val *= divisors[j];
    }
    sum += val;
  }

  cout << sum << endl;
}

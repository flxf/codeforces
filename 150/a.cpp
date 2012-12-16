#include <iostream>
#include <vector>

using namespace std;

#define ULL unsigned long long
#define RT 4000000
#define SQRT 2000

bool isprime[RT];

int main() {
  ULL q;
  cin >> q;
  if (q == 1) {
    cout << 1 << endl << 0 << endl;
    return 0;
  }

  for (int i = 0; i < RT; i++) {
    isprime[i] = true;
  }
  isprime[0] = false;
  isprime[1] = false;

  for (int i = 2; i <= SQRT; i++) {
    if (isprime[i]) {
      for (int j = i*i; j < RT; j += i) {
        isprime[j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 0; i < RT; i++) {
    if (isprime[i]) {
      primes.push_back(i);
    }
  }

  vector<ULL> divisors;
  for (int i = 0; i < primes.size(); i++) {
    while (q % primes[i] == 0) {
      q /= primes[i];
      divisors.push_back(primes[i]);
    }
  }

  if (q > 1) {
    divisors.push_back(q);
  }

  //cout << ":" << divisors.size() << endl;
  //for (int i = 0; i < divisors.size(); i++) {
    //cout << divisors[i] << " ";
  //}
  //cout << endl;

  if (divisors.size() == 1) {
    cout << 1 << endl;
    cout << 0 << endl;
  } else if (divisors.size() == 2) {
    cout << 2 << endl;
  } else {
    cout << 1 << endl << divisors[0] * divisors[1] << endl;
  }
}

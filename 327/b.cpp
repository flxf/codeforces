#include <iostream>
#include <vector>

using namespace std;

#define LIM 10000000
bool is_prime[LIM];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < LIM; i++) {
    is_prime[i] = true;
  }
  is_prime[1] = false;

  for (int i = 2; i * i < LIM; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j < LIM; j += i) {
        is_prime[j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 2; i < LIM; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << primes[i] << " ";
  }
  cout << endl;

  return 0;
}

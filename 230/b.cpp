#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<unsigned long long, bool> psq;
bool is_prime[1000001];
vector<unsigned long long> primes;

int main() {
  for (int i = 2; i <= 1000000; i++) {
    is_prime[i] = true;
  }
  for (int i = 2; i <= 1000; i++) {
    if (!is_prime[i]) {
      continue;
    }
    for (int j = i * i; j <= 1000000; j += i) {
      is_prime[j] = false;
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  unsigned long long t;
  for (int i = 0; i < primes.size(); i++) {
    t = primes[i] * primes[i];
    //cout << t << endl;
    psq[t] = true;
  }

  int n;
  cin >> n;

  unsigned long long x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (psq.find(x) != psq.end()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

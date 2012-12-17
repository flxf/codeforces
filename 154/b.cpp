#include <iostream>
#include <vector>

using namespace std;

#define TOTS 100001
#define SQRT 320

bool is_prime[TOTS];
vector<int> pdivs[TOTS];

int ON[TOTS];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < TOTS; i++) {
    is_prime[i] = true;
  }
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i < SQRT; i++) {
    if (is_prime[i]) {
      for (int j = i*i; j < TOTS; j += i) {
        is_prime[j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 2; i < SQRT; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  pdivs[1].push_back(1);
  for (int i = 2; i < TOTS; i++) {
    int test = i;
    for (int j = 0; j < primes.size(); j++) {
      if (test % primes[j] == 0) {
        pdivs[i].push_back(primes[j]);
        while (test % primes[j] == 0) {
          test /= primes[j];
        }
      }
    }
    if (test != 1) {
      pdivs[i].push_back(test);
    }
  }

  char move;
  int which;
  for (int i = 0; i < m; i++) {
    cin >> move >> which;
    if (move == '+') {
      bool failed = false;
      for (int j = 0; j < pdivs[which].size(); j++) {
        if (ON[pdivs[which][j]] != 0) {
          if (ON[pdivs[which][j]] == which) {
            cout << "Already on" << endl;
            failed = true;
            break;
          } else {
            cout << "Conflict with " << ON[pdivs[which][j]] << endl;
            failed = true;
            break;
          }
        }
      }

      if (!failed) {
        cout << "Success" << endl;
        for (int j = 0; j < pdivs[which].size(); j++) {
          ON[pdivs[which][j]] = which;
        }
      }
    } else {
      bool failed = false;
      for (int j = 0; j < pdivs[which].size(); j++) {
        if (ON[pdivs[which][j]] != which) {
          cout << "Already off" << endl;
          failed = true;
          break;
        } else {
          ON[pdivs[which][j]] = 0;
        }
      }

      if (!failed) {
        cout << "Success" << endl;
      }
    }
  }
}

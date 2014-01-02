#include <iostream>
#include <vector>

using namespace std;

#define MAX 200000

bool isprime[MAX + 1];
int nextprime[MAX + 1];
int cost[500][500];

int main() {
  for (int i = 2; i <= MAX; i++) {
    isprime[i] = true;
  }
  for (int i = 2; i * i <= MAX; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        isprime[j] = false;
      }
    }
  }

  int last = -1;
  for (int i = MAX; i >= 0; i--) {
    if (isprime[i]) {
      last = i;
    }

    nextprime[i] = last;
  }

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> cost[i][j];
      cost[i][j] = nextprime[cost[i][j]] - cost[i][j];
    }
  }

  int best = 100000000;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      sum += cost[i][j];
    }
    best = min(best, sum);
  }

  for (int i = 0; i < m; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += cost[j][i];
    }
    best = min(best, sum);
  }

  cout << best << endl;
}

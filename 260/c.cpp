#include <iostream>

using namespace std;

unsigned long long a[100000];
int dp[100000];
int n;

int dist(int u, int v) {
  if (u <= v) {
    return v - u + 1;
  } else {
    return (n - u) + (v + 1);
  }
}

bool good(int u, int v) {
  if (u <= v) {
    if (u == 0) {
      return dp[v] == dist(u, v);
    } else {
      return (dp[v] - dp[u - 1]) == dist(u, v);
    }
  } else {
    return (dp[n - 1] - (dp[u - 1] - dp[v])) == dist(u, v);
  }
}

int main() {
  int x;
  cin >> n >> x;
  x--;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int mini = 0;
  unsigned long long minv = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] < minv) {
      minv = a[i];
      mini = i;
    }
  }

  for (int i = 0; i < n; i++) {
    a[i] -= minv;
    dp[i] = (a[i] > 0) ? 1 : 0;
  }
  for (int i = 1; i < n; i++) {
    dp[i] = dp[i - 1] + dp[i];
  }

  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      if (i == x) {
        a[i] = minv * n;
        break;
      } else if (good((i + 1) % n, x)) {
        for (int j = (i + 1) % n; ; j++) {
          a[j % n]--;
          if (j % n == x) {
            break;
          }
        }
        a[i] = minv * n + dist((i + 1) % n, x);
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

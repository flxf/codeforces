#include <iostream>

using namespace std;

int dict[1001];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    dict[a]++;
  }

  int best = 0;
  for (int i = 0; i <= 1000; i++) {
    best = max(best, dict[i]);
  }

  if (best <= (n + 1) / 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

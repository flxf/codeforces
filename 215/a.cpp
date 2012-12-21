#include <iostream>

using namespace std;

int a[50];
int b[50];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  int best = 0;
  int bestcount = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[j] % a[i] == 0) {
        if (b[j] / a[i] > best) {
          best = b[j] / a[i];
          bestcount = 1;
        } else if (b[j] / a[i] == best) {
          bestcount++;
        }
      }
    }
  }

  cout << bestcount << endl;
}

#include <iostream>

using namespace std;

int d[1000001];
int main() {
  int n = 1000000;
  for (int i = 0; i <= n; i++) {
    d[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      d[j]++;
    }
  }

  int a, b, c;
  cin >> a >> b >> c;
  int tot = 0;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
        //cout << i << ":" << j << ":" << k << " - " << d[i*j*k] << endl;
        tot = (tot + d[i*j*k]) % 1073741824;
      }
    }
  }

  cout << tot << endl;
}

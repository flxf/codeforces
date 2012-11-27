#include <iostream>
#include "math.h"
#include <cstdio>

using namespace std;

double x[5000];
double y[5000];
double z[5000];

int main() {
  int n;
  cin >> n;

  double rout = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    rout = max(x[i], rout);
  }

  int m;
  cin >> m;
  double pout = 0;
  for (int i = 0; i < m; i++) {
    cin >> y[i];
    pout = max(y[i], pout);
  }

  int k;
  cin >> k;
  double pin = 6000;
  for (int i = 0; i < k; i++) {
    cin >> z[i];
    pin = min(z[i], pin);
  }

  double A, B;
  cin >> A >> B;

  double ans = sqrt(rout*rout / (A / B * pin / pout + 1));
  printf("%.8f\n", ans);
}

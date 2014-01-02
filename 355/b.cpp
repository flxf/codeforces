#include <iostream>

using namespace std;

int a[1000];
int b[1000];

int main() {
  int c1, c2, c3, c4;
  cin >> c1 >> c2 >> c3 >> c4;

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  int acost = c3;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += min(a[i] * c1, c2);
  }
  acost = min(acost, sum);

  int bcost = c3;
  sum = 0;
  for (int i = 0; i < m; i++) {
    sum += min(b[i] * c1, c2);
  }
  bcost = min(bcost, sum);

  cout << min(acost + bcost, c4) << endl;
}

#include <iostream>

using namespace std;

int a[3000];
int b[3000];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  int ait = 0, bit = 0;
  while (ait != n && bit != m) {
    if (a[ait] <= b[bit]) {
      ait++;
      bit++;
    } else {
      bit++;
    }
  }

  //cout << ait << ":" << bit << endl;
  cout << n - ait << endl;
}

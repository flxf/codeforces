#include <iostream>

using namespace std;

int a[5];
int p[50];
unsigned long long b[5];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }


  int r = 0;
  for (int i = 0; i < n; i++) {
    r += p[i];
    for (int j = 4; j >= 0; j--) {
      b[j] += r / a[j];
      r = r % a[j];
    }
  }

  for (int i = 0; i < 5; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
  cout << r << endl;
}

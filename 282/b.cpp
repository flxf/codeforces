#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int n;
  cin >> n;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a, g;
    cin >> a >> g;
    sum += a;
  }


  int req = 0;
  while (abs(sum) > 500 and sum > 0) {
    sum -= 1000;
    req++;
  }

  if (abs(sum) > 500 || req > n) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < req; i++) {
    cout << "G";
  }
  for (int i = req; i < n; i++) {
    cout << "A";
  }
  cout << endl;
}

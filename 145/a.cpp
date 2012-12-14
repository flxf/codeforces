#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;

  int n = a.size();
  int a_fours = 0;
  int b_fours = 0;
  int off = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] == '4') {
      a_fours++;
    }
    if (b[i] == '4') {
      b_fours++;
    }
    if (a[i] != b[i]) {
      off++;
    }
  }

  int diff = abs(a_fours - b_fours);
  off -= diff;
  cout << off / 2 + diff << endl;
}

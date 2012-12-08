#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a[4];
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  sort(a, a+4);

  int same = 0;
  for (int i = 1; i < 4; i++) {
    if (a[i] == a[i - 1]) {
      same++;
    }
  }

  cout << same << endl;
}

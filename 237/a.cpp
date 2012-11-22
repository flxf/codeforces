#include <iostream>

using namespace std;

int main() {
  int m;
  cin >> m;

  int best = 1;
  int acc = 0;
  int lh = -1, lm = -1;
  int ch = 0, cm = 0;

  for (int i = 0; i < m; i++) {
    cin >> ch >> cm;
    if (ch == lh && cm == lm) {
      acc++;
    } else {
      if (acc > best) {
        best = acc;
      }
      lh = ch;
      lm = cm;
      acc = 1;
    }
  }

  if (acc > best) {
    best = acc;
  }

  cout << best << endl;
}

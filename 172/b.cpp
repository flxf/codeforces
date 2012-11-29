#include <iostream>

using namespace std;

int seen[100001];

int main() {
  int a, b, m, r;
  cin >> a >> b >> m >> r;

  seen[r] = 1;
  int pos = 2;
  while (true) {
    r = (a * r + b) % m;
    if (seen[r]) {
      break;
    }
    seen[r] = pos;
    pos++;
  }

  cout << pos - seen[r] << endl;
}

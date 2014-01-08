#include <iostream>
#include <cstdlib>

using namespace std;

int sign(int n) {
  return (n < 0) ? -1 : 1;
}

int main() {
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  int rook = 0;
  if (r1 != r2) {
    rook++;
  }
  if (c1 != c2) {
    rook++;
  }

  int king = 0;
  int dR = r2 - r1;
  int dC = c2 - c1;
  int m = min(abs(dR), abs(dC));

  king += m;
  dR -= m * sign(dR);
  dC -= m * sign(dC);
  king += abs(dR) + abs(dC);

  int bishop = 0;
  int startoddity = (r1 + c1) % 2;
  int endoddity = (r2 + c2) % 2;
  if (startoddity == endoddity) {
    dR = r2 - r1;
    dC = c2 - c1;
    if (abs(dR) == abs(dC)) {
      bishop = 1;
    } else {
      bishop = 2;
    }
  }

  cout << rook << " " << bishop << " " << king << endl;
}

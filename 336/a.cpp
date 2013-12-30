#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  int side = abs(x) + abs(y);

  if (x < 0) {
    if (y < 0) {
      cout << -1 * side << " " << 0 << " " << 0 << " " << -1 * side << endl;
    } else {
      cout << -1 * side << " " << 0 << " " << 0 << " " << side << endl;
    }
  } else {
    if (y < 0) {
      cout << 0 << " " << -1 * side << " " << side << " " << 0 << endl;
    } else {
      cout << 0 << " " << side << " " << side << " " << 0 << endl;
    }
  }
}

#include <iostream>

using namespace std;

int gcd(int u, int v) {
  if (v == 0) {
    return u;
  }
  return gcd(v, u % v);
}

int lcm(int u, int v) {
  int g = gcd(u, v);
  return u * v / g;
}

int main() {
  int x, y, a, b;
  cin >> x >> y >> a >> b;

  int l = lcm(x, y);
  
  int lowest_in_range = (a / l) * l;
  if (a % l > 0) {
    lowest_in_range += l;
  }
  int highest_in_range = (b / l) * l;

  //cout << lowest_in_range << ":" << highest_in_range << endl;

  // works for lcm > a and b
  if (highest_in_range < lowest_in_range) {
    cout << 0 << endl;
  } else {
    cout << (highest_in_range - lowest_in_range) / l + 1 << endl;
  }
}

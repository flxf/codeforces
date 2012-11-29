#include <iostream>

using namespace std;

int gcd(int n, int d) {
  if (d == 0) {
    return n;
  }
  return gcd(d, n % d);
}

int main() {
  int xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;

  long long u1, v1;
  u1 = xb - xa;
  v1 = yb - ya;
  //if (u1 == 0) {
    //v1 = 1;
  //} else if (v1 == 0) {
    //u1 = 1;
  //} else {
    //int d = gcd(u1, v1);
    //u1 /= d;
    //v1 /= d;
  //}

  long long u2, v2;
  u2 = xc - xb;
  v2 = yc - yb;
  //if (u2 == 0) {
    //v2 = 1;
  //} else if (v2 == 0) {
    //u2 = 1;
  //} else {
    //int d = gcd(u2, v2);
    //u2 /= d;
    //v2 /= d;
  //}

  long long cross = u1 * v2 - u2 * v1;
  //cout << u1 << ":" << v1 << endl;
  //cout << u2 << ":" << v2 << endl;
  if (cross == 0) {
    cout << "TOWARDS" << endl;
  } else if (cross > 0) {
    cout << "LEFT" << endl;
  } else {
    cout << "RIGHT" << endl;
  }

}

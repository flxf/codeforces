#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int a, b, c;
  int d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int u = d - a;
  int v = e - b;

  double dist = sqrt(u*u + v*v);
  if (dist + f <= c) {
    cout << setprecision(9) << abs((dist + f) - c) / 2 << endl;
    return 0;
  } else if (dist + c <= f) {
    cout << setprecision(9) << abs((dist + c) - f) / 2 << endl;
    return 0;
  } else if (dist <= c + f) {
    cout << 0 << endl;
    return 0;
  }

  //cout << dist << endl;

  double firstdist = c;
  double seconddist = dist - f;

  double U = u / dist * firstdist + a;
  double V = v / dist * firstdist + b;

  double X = u / dist * seconddist + a;
  double Y = v / dist * seconddist + b;

  double lastdist = sqrt((X - U)*(X - U) + (Y - V)*(Y - V));
  cout << setprecision(9) << lastdist / 2 << endl;

  //cout << U << ":" << V << endl;

  //U = u / dist * seconddist;
  //V = v / dist * seconddist;
  //cout << U << ":" << V << endl;
}

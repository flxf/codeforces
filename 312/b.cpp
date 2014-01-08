#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;

  double prob = a / b;
  double R = (1 - c / d) * (1 - a / b);
  //double next = prob;
  //while (true) {
    //cout << next << endl;
    //next = next * (1 - c / d) * (a / b);
    //if (next < 0.000000001) {
      //break;
    //}
    //prob += next;
  //}

  cout << setprecision(10) << prob / (1 - R) << endl;
}

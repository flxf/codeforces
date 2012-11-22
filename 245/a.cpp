#include <iostream>

using namespace std;

int x[2];
int y[2];

int main() {
  int n;
  cin >> n;

  int ti, xi, yi;
  for (int i = 0; i < n; i++) {
    cin >> ti >> xi >> yi;
    ti--;

    x[ti] += xi;
    y[ti] += yi;
  }

  for (int i = 0; i < 2; i++) {
    if (x[i] >= y[i]) {
      cout << "LIVE" << endl;
    } else {
      cout << "DEAD" << endl;
    }
  }
}

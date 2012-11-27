#include <iostream>

using namespace std;

int points[201];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < 2*n + 1; i++) {
    cin >> points[i];
  }

  for (int i = 1; i < 2*n + 1; i += 2) {
    if (k > 0 && points[i] > points[i-1] + 1 && points[i] > points[i+1] + 1) {
      points[i]--;
      k--;
    }
  }

  for (int i = 0; i < 2*n + 1; i++) {
    cout << points[i] << " ";
  }
  cout << endl;
}

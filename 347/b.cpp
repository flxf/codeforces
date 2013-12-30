#include <iostream>

using namespace std;

int a[100000];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int correct = 0;
  bool twofer = false;
  for (int i = 0; i < n; i++) {
    if (a[i] == i) {
      correct++;
    } else if (a[a[i]] == i) {
      twofer = true;
    }
  }

  if (correct == n) {
    cout << n << endl;
  } else if (twofer) {
    cout << correct + 2 << endl;
  } else {
    cout << correct + 1 << endl;
  }
}

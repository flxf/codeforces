#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];
int n;

bool is_sorted() {
  for (int i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n;

  int mx = a[0];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    //if (i > 0 && a[i] == a[i - 1]) { // collapse values!
      //i--;
      //n--;
    //}
  }

  int wrong = 0;
  int wp[2];
  for (int i = 1; i < n; i++) {
    mx = max(a[i], mx);
    if (a[i] < mx) {
      if (wrong == 2) {
        wrong++;
        break;
      }

      wp[wrong] = i;
      wrong++;
    }
  }

  if (wrong > 2) {
    cout << "NO" << endl;
    return 0;
  }

  if (wrong == 0) {
    cout << "YES" << endl;
    return 0;
  }

  if (wrong == 1) {
    swap(a[wp[0]], a[wp[0] - 1]);
  } else {
    swap(a[wp[0] - 1], a[wp[1]]);
  }

  if (is_sorted()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

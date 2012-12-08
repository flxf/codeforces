#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];
int b[100000];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b,b+n);

  int wrong = 0;
  int pi[2];
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      if (wrong == 2) {
        cout << "NO" << endl;
        return 0;
      }
      pi[wrong] = i;
      wrong++;
    }
  }

  if (wrong == 0 || (a[pi[0]] == b[pi[1]] && a[pi[1]] == b[pi[0]])) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

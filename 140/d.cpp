#include <iostream>
#include <algorithm>

using namespace std;

int a[100];

int ans(int x) {
  return (x < 0) ? x * -1 : x;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a,a+n);

  int tot = 10;
  int solv = 0;
  int pen = 0;
  for (int i = 0; i < n; i++) {
    int f = tot + a[i];
    if (f > 720) {
      break;
    }

    if (f < 360) {
      // no penalty
      solv++;
    } else {
      solv++;
      pen += (f - 360);
    }

    tot = f;
  }

  cout << solv << " " << pen << endl;
}

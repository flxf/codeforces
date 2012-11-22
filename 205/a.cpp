#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];

int main() {
  int n;
  cin >> n;

  int besti = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < a[besti]) {
      besti = i;
    }
  }
  sort(a,a+n);

  if (a[0] == a[1]) {
    cout << "Still Rozdil" << endl;
  } else {
    cout << besti + 1 << endl;
  }
}

#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];
int n;

void print() {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  int k;
  cin >> n >> k;

  if (n == k) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < 100000; i++) {
    a[i] = i + 1;
  }

  if (n - 1 == k) {
    print();
    return 0;
  }

  int bad = n - k;
  int iter;

  if (bad % 2 == 0) {
    swap(a[0], a[1]);
    bad -= 2;
    iter = 2;
  } else {
    swap(a[0], a[1]);
    swap(a[1], a[2]);
    bad -= 3;
    iter = 3;
  }

  while (bad > 0) {
    swap(a[iter], a[iter+1]);
    bad -= 2;
    iter += 2;
  }

  print();
}

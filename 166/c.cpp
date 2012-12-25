#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];

int abs(int b) {
  if (b < 0) {
    return b * -1;
  }
  return b;
}

int main() {
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);

  int beg = n;
  int end = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      beg = min(beg, i);
      end = max(end, i);
    }
  }

  int add = 0;
  if (end == -1) {
    add = 1;
    beg = n;
    end = n;
    for (int i = 0; i < n; i++) {
      if (a[i] > x) {
        beg = i;
        end = i;
        break;
      }
    }
    n++;
  }

  int med;
  while (true) {
    med = (n - 1) / 2;
    //cout << beg << ":" << end << ":" << med << endl;
    if (med >= beg && med <= end) {
      cout << add << endl;
      break;
    }
    n++;
    end++;
    add++;
  }
}

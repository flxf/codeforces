#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;

  int n, m;
  cin >> n >> m;

  int l, r;
  if (m % 2 == 0) {
    l = m / 2 - 1;
    r = m / 2;
    v.push_back(l);
    v.push_back(r);
  } else {
    l = m / 2;
    r = m / 2;
    v.push_back(l);
  }

  while (r - l + 1 < m) {
    l--;
    v.push_back(l);
    r++;
    v.push_back(r);
  }

  for (int i = 0; i < n; i++) {
    cout << v[i % m] + 1 << endl;
  }


}

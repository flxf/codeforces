#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int> > a;
  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    a.push_back(make_pair(v, i));
  }
  sort(a.begin(), a.end());

  int last = -1;
  for (int i = 0; i < n; i++) {
  }


}

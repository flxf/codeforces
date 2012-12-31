#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int> > a;
  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    a.push_back(make_pair(v, i + 1));
  }
  sort(a.begin(), a.end());

  vector<int> one;
  vector<int> two;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      one.push_back(a[i].second);
    } else {
      two.push_back(a[i].second);
    }
  }

  cout << one.size() << endl;
  for (int i = 0; i < one.size(); i++) {
    cout << one[i] << " ";
  }
  cout << endl;

  cout << two.size() << endl;
  for (int i = 0; i < two.size(); i++) {
    cout << two[i] << " ";
  }
  cout << endl;
}

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> arr[300000];

bool byscore(pair<int, int> a, pair<int, int> b) {
  if (a.second < b.second) {
    return true;
  }
  return false;
}

int main() {
  int n; 
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr[i] = make_pair(i, a);
  }

  sort(arr, arr+n, byscore);

  int last = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i].second <= last) {
      arr[i] = make_pair(arr[i].first, last + 1);
      last = last + 1;
    } else {
      last = arr[i].second;
    }
  }

  sort(arr, arr+n);
  for (int i = 0; i < n; i++) {
    cout << arr[i].second << " ";
  }
  cout << endl;
}

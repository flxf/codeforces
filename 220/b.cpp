#include <iostream>
#include <map>
#include <vector>

using namespace std;

int a[100000];
map<int, int* > dp;
map<int, int> cnt;

int get(int* arr, int p) {
  if (p < 0) {
    return 0;
  }
  return arr[p];
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (cnt.find(a[i]) == cnt.end()) {
      cnt[a[i]] = 1;
    } else {
      cnt[a[i]] = cnt[a[i]] + 1;
    }
  }

  map<int, int>::iterator it;
  for (it = cnt.begin(); it != cnt.end(); it++) {
    int v = it->first;
    int num = it->second;

    if (num >= v) {
      dp[v] = new int[100000];
      int* arr = dp[v];

      arr[0] = (a[0] == v) ? 1 : 0;
      for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] + ((a[i] == v) ? 1 : 0);
      }

      //cout << v << endl;
      //cout << "=================" << endl;
      //for (int i = 0; i < n; i++) {
        //cout << arr[i] << " ";
      //}
      //cout << endl;
      //cout << "=================" << endl;
    }
  }

  map<int, int*>::iterator et;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;

    int win = 0;
    for (et = dp.begin(); et != dp.end(); et++) {
      int v = et->first;
      int* arr = et->second;

      int bef = get(arr, l - 1);
      int aff = get(arr, r);
      int how = aff - bef;

      //cout << v << " " << how << endl;

      if (how == v) {
        win++;
      }
    }
    cout << win << endl;
  }


}

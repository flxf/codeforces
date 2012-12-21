#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int arr[100000];
int stress[100000];
int n, k;
int cnt;

bool same(int pos) {
  if (pos == 0 || pos == cnt - 1) {
    return false;
  }
  return arr[pos - 1] == arr[pos + 1];
}

int main() {
  cin >> n >> k;

  vector<pair<int, int> > a;
  cin >> arr[0];
  arr[0]--;
  //a.push_back(make_pair(arr[0], 0));

  int v;
  cnt = 1;
  for (int i = 1; i < n; i++) {
    cin >> v;
    v--;
    if (v == arr[cnt - 1]) {
      continue;
    }
    arr[cnt] = v;
    //a.push_back(make_pair(v, cnt));
    cnt++;
  }
  //sort(a.begin(), a.end());

  for (int i = 0; i < cnt; i++) {
    if (same(i)) {
      stress[arr[i]] += 2;
    } else {
      stress[arr[i]] ++;
    }
  }

  int best = 0;
  for (int i = 0; i < k; i++) {
    if (stress[i] > stress[best]) {
      best = i;
    }
  }

  cout << best + 1 << endl;
}

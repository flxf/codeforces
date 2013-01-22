// WARNING: I read the editorial for this one =(

#include <iostream>
#include <set>

using namespace std;

int a[1000000];
bool seen[3000000];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  set<int> support;
  set<int>::iterator it;
  int next[30];
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    //cout << "========" << support.size() << endl;
    for (it = support.begin(); it != support.end(); it++) {
      //cout << *it << endl;
      next[cnt] = (*it) | a[i];
      seen[next[cnt]] = true;
      cnt++;
    }

    support.clear();
    for (int j = 0; j < cnt; j++) {
      support.insert(next[j]);
    }

    seen[a[i]] = true;
    support.insert(a[i]);
  }

  int ans = 0;
  for (int i = 0; i < 3000000; i++) {
    if (seen[i]) {
      //cout << "->" << i << endl;
      ans++;
    }
  }

  cout << ans << endl;
}

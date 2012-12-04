#include <iostream>

using namespace std;

int seen[100001];
int a[100001];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int bot = k;
  int top = n;
  int l, r;
  while (bot <= top) {
    int mid = (top + bot) / 2;
    //cout << mid << endl;
    for (int i = 0; i <= 100000; i++) {
      seen[i] = 0;
    }

    int distinct = 0;
    for (int i = 0; i < mid; i++) {
      seen[a[i]]++;
      if (seen[a[i]] == 1) {
        distinct++;
      }
    }

    if (distinct >= k) {
      top = mid - 1;
      l = 0;
      r = mid - 1;
      goto next;
    }

    for (int i = mid; i < n; i++) {
      //cout << "idx(" << i << ")" << a[i - 1] << " removed ";
      seen[a[i - mid]]--;
      //cout << seen[a[i - 1]] << endl;
      if (seen[a[i - mid]] == 0) {
        distinct--;
      }
      seen[a[i]]++;
      if (seen[a[i]] == 1) {
        distinct++;
      }
      //cout << i << "D" << distinct << endl;

      if (distinct >= k) {
        top = mid - 1;
        r = i;
        l = i - mid + 1;
        goto next;
      }
    }

    bot = mid + 1;

    next:
      continue;
  }

  if (bot == n + 1) {
    cout << "-1 -1" << endl;
  } else {
    //cout << "HELLO" << bot << endl;
    cout << (l + 1) << " " << (r + 1) << endl;
  }
}

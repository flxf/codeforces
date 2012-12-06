#include <iostream>

using namespace std;

int t[100];
int fp;
int n;

bool rec(int oh, int wow, int pos, int sum, int mx) {
  //cout << oh << ":" << wow << ":" << pos << ":" << sum << ":" << mx << endl;
  if (mx > 50000) {
    return false;
  }
  if (pos > n) {
    return false;
  }
  if (oh == 0 && wow == 0) {
    fp = pos;
    return true;
  }

  bool ret;
  if (oh > 0) {
    if (mx < sum) {
      t[pos] = mx + 1;
      ret = rec(oh - 1, wow, pos + 1, sum + mx + 1, mx + 1);
      if (ret) {
        return ret;
      }
    } else {
      t[pos] = 1;
      ret = rec(oh, wow, pos + 1, sum + 1, mx);
      if (ret) {
        return ret;
      }
    }
  }

  if (wow > 0) {
    t[pos] = sum + 1;
    ret = rec(oh, wow - 1, pos + 1, sum + sum + 1, sum + 1);
    if (ret) {
      return ret;
    }
  }

  return false;
}

int main() {
  int a, b;
  cin >> n >> a >> b;

  t[0] = 1;
  bool has = rec(a, b, 1, 1, 1);
  if (!has) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < fp; i++) {
    cout << t[i] << " ";
  }
  for (int i = fp; i < n; i++) {
    cout << 1 << " ";
  }
  cout << endl;
}

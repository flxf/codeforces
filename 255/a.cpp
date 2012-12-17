#include <iostream>

using namespace std;

  int ans[3];
int main() {
  int n;
  cin >> n;

  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    ans[i % 3] += v;
  }

  if (ans[0] >= ans[1] && ans[0] >= ans[2]) {
    cout << "chest" << endl;
  } else if (ans[1] >= ans[0] && ans[1] >= ans[2]) {
    cout << "biceps" << endl;
  } else {
    cout << "back" << endl;
  }
}

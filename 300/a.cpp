#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> negs, zeros, pos;

  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a < 0) {
      negs.push_back(a);
    } else if (a == 0) {
      zeros.push_back(a);
    } else {
      pos.push_back(a);
    }
  }

  // we are guaranteed soln exists
  if (pos.size() > 0) {
    // negs will also be positive...
    cout << 1 << " " << negs[0] << endl;
    cout << 1 << " " << pos[0] << endl;
    cout << zeros.size() + negs.size() + pos.size() - 2;
    for (int i = 0; i < zeros.size(); i++) {
      cout << " 0";
    }
    for (int i = 1; i < negs.size(); i++) {
      cout << " " << negs[i];
    }
    for (int i = 1; i < pos.size(); i++) {
      cout << " " << pos[i];
    }
    cout << endl;
  } else {
    cout << 1 << " " << negs[0] << endl;
    cout << 2 << " " << negs[1] << " " << negs[2] << endl;
    cout << zeros.size() + negs.size() - 3;
    for (int i = 0; i < zeros.size(); i++) {
      cout << " 0";
    }
    for (int i = 3; i < negs.size(); i++) {
      cout << " " << negs[i];
    }
    cout << endl;
  }

}

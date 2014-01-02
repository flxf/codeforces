#include <iostream>
#include <string>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;

  if (a.size() != b.size()) {
    cout << "NO" << endl;
    return 0;
  }

  int aone = 0, bone = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '1') {
      aone++;
    }
    if (b[i] == '1') {
      bone++;
    }
  }

  if (aone == 0) {
    if (bone == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }

    return 0;
  }

  if (bone > 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

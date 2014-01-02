#include <iostream>
#include <string>

using namespace std;

int main() {
  long long left = 0, right = 0;

  string s;
  cin >> s;

  int pivot = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '^') {
      pivot = i;
      break;
    }
  }

  for (int i = 1; pivot - i >= 0; i++) {
    if (s[pivot - i] >= '0' && s[pivot - i] <= '9') {
      left += (s[pivot - i] - '0') * i;
    }
  }

  for (int i = 1; pivot + i < s.size(); i++) {
    if (s[pivot + i] >= '0' && s[pivot + i] <= '9') {
      right += (s[pivot + i] - '0') * i;
    }
  }

  if (left > right) {
    cout << "left" << endl;
  } else if (right > left) {
    cout << "right" << endl;
  } else {
    cout << "balance" << endl;
  }
}

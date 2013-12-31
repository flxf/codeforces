#include <iostream>

using namespace std;

void print_digit(int n) {
  if (n >= 5) {
    cout << "-O|";
  } else {
    cout << "O-|";
  }

  n = n % 5;
  for (int i = 0; i < n; i++) {
    cout << "O";
  }
  cout << "-";
  for (int i = n; i < 4; i++) {
    cout << "O";
  }
  cout << endl;
}

int main() {
  string s;
  cin >> s;

  for (int i = s.size() - 1; i >= 0; i--) {
    print_digit(s[i] - '0');
  }
}

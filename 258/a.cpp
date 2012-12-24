#include <string>
#include <iostream>

using namespace std;

int main() {
  string line;
  cin >> line;

  int zero = 0;
  for (int i = 0; i < line.length(); i++) {
    if (line[i] == '0') {
      zero = i;
      break;
    }
  }

  for (int i = 0; i < line.length(); i++) {
    if (i == zero) {
      continue;
    }
    cout << line[i];
  }
  cout << endl;
}

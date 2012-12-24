#include <iostream>
#include <string>

using namespace std;

int main() {
  string line;
  int b = 0, w = 0;
  for (int i = 0; i < 8; i++) {
    cin >> line;
    for (int j = 1; j < 8; j++) {
      if (line[j] == line[j-1]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  cout << "YES" << endl;
}

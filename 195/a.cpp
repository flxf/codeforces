#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int downloadtime = (c * a / b);
  if (c * a % b != 0) {
    downloadtime++;
  }

  for (int i = 0; i < 2000000; i++) {
    if (downloadtime <= i + c) {
      cout << i << endl;
      return 0;
    }
  }
}

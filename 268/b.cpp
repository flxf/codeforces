#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int solved = 0;
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    ans += i;
    ans += (i - 1) * solved;
    solved++;
  }

  cout << ans << endl;
}

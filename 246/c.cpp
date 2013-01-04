#include <iostream>
#include <algorithm>

#define ull unsigned long long

using namespace std;

int a[50];
int n, k;

int main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a,a+n);

  for (int l = 1; l <= n; l++) {
    for (int i = 0; i <= n - l; i++) {
      if (k == 0) {
        goto end;
      }
      cout << l;

      for (int j = n - 1; j >= n - l + 1; j--) {
        cout << " " << a[j];
      }
      cout << " " << a[n - l - i] << endl;
      k--;
    }
  }

end:
  return 0;
}

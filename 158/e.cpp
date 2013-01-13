#include <iostream>

using namespace std;

int t[4000];
int d[4000];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> t[i] >> d[i];
  }

  int biggest = 0;
  //for (int i = 0; i < n - k + 1; i++) {
  for (int i = 0; i < n; i++) {
    int igstart = i;
    int igend = i + k;

    int last = 0;
    for (int j = 0; j < n; j++) {
      if (j >= igstart && j < igend) {
        continue;
      }

      int callstart = max(t[j], last + 1);
      int callend = callstart + d[j] - 1;
      biggest = max(biggest, callstart - last - 1);
      cout << "start: " << callstart << " - end: " << callend << endl;
      cout << "i: " << i << " j: " << j << " T:" << biggest << endl;
      last = callend;
    }

    biggest = max(biggest, 86401 - last - 1);
    cout << "T:" << biggest << endl;
  }

  cout << biggest << endl;
}

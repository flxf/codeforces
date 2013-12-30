#include <iostream>
#include <vector>

using namespace std;

int squares[101];

int main() {
  int n;
  cin >> n;

  vector<int> a[100];

  int fork = (n * n) / 2;
  for (int i = 1; i <= fork; i++) {
    a[(i - 1) % n].push_back(i);
  }
  for (int i = fork + 1; i <= n * n; i++) {
    a[(n - 1) - ((i - 1) % n)].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i].size(); j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

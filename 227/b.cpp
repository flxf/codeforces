#include <iostream>

using namespace std;

int p[100000];

int main() {
  int n;
  cin >> n;

  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    a--;
    p[a] = i;
  }

  int m;
  cin >> m;

  unsigned long long one = 0, two = 0;
  for (int i = 0; i < m; i++) {
    cin >> a;
    a--;
    one += p[a] + 1;
    two += n - p[a];
  }

  cout << one << " " << two << endl;
}

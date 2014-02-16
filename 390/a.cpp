#include <set>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  set<int> xes, yes;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    xes.insert(a);
    yes.insert(b);
  }

  cout << min(xes.size(), yes.size()) << endl;
}

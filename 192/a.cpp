#include <iostream>
#include <set>
#include <vector>

#define ULL unsigned long long

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<ULL> v;
  set<ULL> s;

  for (ULL k = 1; ; k++) {
    ULL m = k * (k + 1) / 2;
    if (m > 1000000000ULL) {
      break;
    }

    v.push_back(m);
    s.insert(m);
  }

  for (int i = 0; i < v.size(); i++) {
    if (s.find(n - v[i]) != s.end()) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}

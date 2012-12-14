#include <iostream>
#include <set>

#define ULL unsigned long long

using namespace std;

int a[50];
set<ULL> s;
int n, k;

int main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    used[i] = false;
    cin >> a[i];
  }

  rec(0, 0, 0);
}

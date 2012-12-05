#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, int> clients[100000];

unsigned long long n, d, a, b;

int main() {
  cin >> n >> d >> a >> b;

  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    clients[i] = make_pair(x * a + y * b, i + 1);
  }
  sort(clients,clients+n);

  unsigned long long used = 0;
  int op = 0;
  while (used < d && op < n) {
    if (clients[op].first + used <= d) {
      used += clients[op].first;
      op++;
    } else {
      break;
    }
  }

  cout << op << endl;
  for (int i = 0; i < op; i++) {
    cout << clients[i].second << endl;
  }
}

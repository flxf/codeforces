#include <iostream>
#include <utility>

using namespace std;

bool ret(pair<int, int> target, pair<int, int> a, pair<int, int> b) {
  return (target.first >= min(a.first, b.first)
      && target.first <= max(a.first, b.first)
      && target.second >= min(a.second, b.second)
      && target.second <= max(a.second, b.second));
}

int main() {
  int x, y;
  cin >> x >> y;

  pair<int, int> target = make_pair(x, y);
  if (target == make_pair(0, 0) || target == make_pair(1, 0)) {
    cout << 0 << endl;
    return 0;
  }

  pair<int, int> last = make_pair(1, 0);

  int level = 1;
  int turns = 1;

  while (true) {
    pair<int, int> next = make_pair(level, level);
    if (ret(target, last, next)) {
      cout << turns << endl;
      return 0;
    }
    last = next;
    turns++;
    
    next = make_pair(-1 * level, level);
    if (ret(target, last, next)) {
      cout << turns << endl;
      return 0;
    }
    last = next;
    turns++;

    next = make_pair(-1 * level, -1 * level);
    if (ret(target, last, next)) {
      cout << turns << endl;
      return 0;
    }
    last = next;
    turns++;

    next = make_pair(level + 1, -1 * level);
    if (ret(target, last, next)) {
      cout << turns << endl;
      return 0;
    }
    last = next;
    turns++;
    level++;
  }
}

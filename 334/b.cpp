#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main() {
  set<pair<int, int> > points;
  set<int> xes;
  set<int> yes;

  for (int i = 0; i < 8; i++) {
    int x, y;
    cin >> x >> y;

    xes.insert(x);
    yes.insert(y);
    points.insert(make_pair(x, y));
  }

  if (points.size() != 8) {
    cout << "ugly" << endl;
    return 0;
  }
  if (xes.size() != 3) {
    cout << "ugly" << endl;
    return 0;
  }
  if (yes.size() != 3) {
    cout << "ugly" << endl;
    return 0;
  }

  for (set<int>::iterator it = xes.begin(); it != xes.end(); it++) {
    for (set<int>::iterator jt = yes.begin(); jt != yes.end(); jt++) {
      int I = distance(xes.begin(), it);
      int J = distance(yes.begin(), jt);
      if (I != 1 || J != 1) {
        if (points.count(make_pair(*it, *jt)) == 0) {
          cout << "ugly" << endl;
          return 0;
        }
      }
    }
  }

  cout << "respectable" << endl;
}

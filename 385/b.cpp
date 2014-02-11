#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;

  vector<int> bears;
  int last = -4;
  while ((last = s.find("bear", last + 4)) != -1) {
    bears.push_back(last);
  }

  long long cnt = 0;

  for (int i = 0; i < s.size(); i++) {
    int li = lower_bound(bears.begin(), bears.end(), i) - bears.begin();
    if (li == bears.size()) {
      break;
    }

    int least = bears[li];
    int diff = (s.size() - least - 3);
    //cout << "least: " << least << " , " << diff << ":" << endl;
    cnt += diff;
  }

  cout << cnt << endl;
}

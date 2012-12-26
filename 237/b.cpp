#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int c[50];

int main() {
  int n;
  cin >> n;

  int s = 0;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    s += c[i];
  }

  vector<int> numbers;
  vector<int> copy;
  vector<pair<int, int> > pos;
  int v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < c[i]; j++) {
      cin >> v;
      numbers.push_back(v);
      copy.push_back(v);
      pos.push_back(make_pair(i, j));
    }
  }

  sort(numbers.begin(), numbers.end());

  stringstream oss;
  int cnt = 0;
  for (int i = 0; i < s; i++) {
    if (copy[i] != numbers[i]) {
      for (int j = 0; j < s; j++) {
        if (copy[j] == numbers[i]) {
          swap(copy[i], copy[j]);
          cnt++;
          oss << (pos[i].first + 1) << " " << (pos[i].second + 1) << " " << (pos[j].first + 1) << " " << (pos[j].second + 1) << endl;
          break;
        }
      }
    }
  }

  cout << cnt << endl;
  cout << oss.str() << endl;

  //for (int i = 0; i < s; i++) {
    //cout << copy[i] << " ";
  //}
  //cout << endl;
}

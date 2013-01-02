#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

#define ull unsigned long long

vector<pair<ull, int> > carts[1000];
bool discounted[1000];

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<ull, int> > stool;
  vector<pair<ull, int> > chair;

  ull c, t;
  for (int i = 0; i < n; i++) {
    cin >> c >> t;
    if (t == 1) {
      stool.push_back(make_pair(c * 10, i + 1));
    } else {
      chair.push_back(make_pair(c * 10, i + 1));
    }
  }

  sort(stool.begin(), stool.end());
  reverse(stool.begin(), stool.end());

  for (int i = 0; i < min(k, (int)stool.size()); i++) {
    carts[i].push_back(stool[i]);
    discounted[i] = true;
  }

  for (int i = k; i < stool.size(); i++) {
    carts[k - 1].push_back(stool[i]);
  }
  for (int i = 0; i < chair.size(); i++) {
    carts[min((int)(stool.size() + i), k - 1)].push_back(chair[i]);
    //carts[k - 1].push_back(chair[i]);
  }

  ull value = 0;
  for (int i = 0; i < k; i++) {
    if (carts[i].size() > 0) {
      ull mn = carts[i][0].first;
      ull sum = 0;
      for (int j = 0; j < carts[i].size(); j++) {
        mn = min(mn, carts[i][j].first);
        sum += carts[i][j].first;
      }

      if (discounted[i]) {
        value += (sum - mn / 2);
      } else {
        value += sum;
      }
    }
  }

  cout << value / 10 << "." << value % 10 << endl;
  for (int i = 0; i < k; i++) {
    cout << carts[i].size() << " ";
    for (int j = 0; j < carts[i].size(); j++) {
      cout << carts[i][j].second << " ";
    }
    cout << endl;
  }
}

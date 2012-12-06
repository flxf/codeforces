#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> greed;

int main() {
  int s, k;
  cin >> s >> k;
  int origs = s;

  v.push_back(1);
  v.push_back(1);

  int sum = 2;
  for (int i = 1; i < k; i++) {
    v.push_back(sum);
    sum += sum;
    if (sum > 1000000000) {
      break;
    }
  }
  for (int i = k + 1; ; i++) {
    if (sum > 1000000000) {
      break;
    }
    sum -= v[i - k - 1];
    v.push_back(sum);
    sum += v[i];
  }

  //for (int i = 0; i < v.size(); i++) {
    //cout << v[i] << endl;
  //}

  for (int i = v.size() - 1; i >= 0; i--) {
    if (s >= v[i]) {
      s -= v[i];
      greed.push_back(v[i]);
    }
  }
  greed.push_back(0);

  cout << greed.size() << endl;
  for (int i = 0; i < greed.size(); i++) {
    cout << greed[i] << " ";
  }
  cout << endl;



}

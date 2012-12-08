#include <iostream>
#include <vector>

using namespace std;

int a[100];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int neg = 0;
  vector<int> grief;
  grief.push_back(-1);

  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      neg++;
      if (neg == 3) {
        grief.push_back(i - 1);
        neg = 1;
      }
    }
  }
  grief.push_back(n - 1);

  cout << grief.size() - 1 << endl;
  for (int i = 1; i < grief.size(); i++) {
    cout << grief[i] - grief[i - 1] << " ";
  }
  cout << endl;
}

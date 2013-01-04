#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int a[100000];

int main() {
  int n, k;
  cin >> n >> k;

  int v;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);

  k--;
  cout << a[k / n] << " " << a[k % n] << endl;


  //int x = 0;
  //while (true) {
    //if (seen[a[x]] > 1) {
      //if (k < cnt) {
        //cout << a[x] << " " << a[k] << endl;
        //return 0;
      //} else {
        //x++;
        //k -= cnt;
      //}
    //} else {
      //if (k < cnt - 1) {
        //if (k < x) {
          //cout << a[x] << " " << a[k] << endl;
          //return 0;
        //} else {
          //cout << a[x] << " " << a[k + 1] << endl;
          //return 0;
        //}
      //} else {
        //x++;
        //k -= (cnt - 1);
      //}
    //}
  //}
}

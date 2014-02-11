#include <iostream>
#include <utility>

using namespace std;

int max_len[1000001];
int dp[1000001];
int a[10];

int rec(int v) {
  if (v == 0) {
    return 0;
  }

  if (max_len[v] != -2) {
    return max_len[v];
  }

  int bestd = 0;
  int bestl = 0;

  for (int i = 1; i <= 9; i++) {
    int rem = v - a[i];
    if (rem < 0) {
      continue;
    }

    if (rec(rem) + 1 >= bestl) {
      bestl = rec(rem) + 1;
      bestd = i;
    }
  }

  max_len[v] = bestl;
  dp[v] = bestd;

  return max_len[v];
}

void printr(int v) {
  if (v == 0 || dp[v] == 0) {
    cout << endl;
    return;
  }

  cout << dp[v];
  printr(v - a[dp[v]]);
}

int main() {
  int v;
  cin >> v;

  for (int i = 1; i <= 9; i++) {
    cin >> a[i];
  }

  max_len[0] = 0;
  for (int i = 1; i <= 1000000; i++) {
    max_len[i] = -2;
  }

  for (int i = 1; i <= v; i++) {
    rec(i);
  }

  dp[0] = 0;
  max_len[0] = 0;

  //int besti = 0;
  //for (int i = 1; i <= v; i++) {
    //if (max_len[i] > max_len[besti]) {
      //besti = i;
    //} else if (max_len[i] == max_len[besti] && dp[i] > dp[besti]) {
      //besti = i;
    //}
  //}

  //if (besti == 0) {
    //cout << -1 << endl;
  //} else {
    //printr(besti);
  //}
  
  if (dp[v] == 0) {
    cout << -1 << endl;
  } else {
    printr(v);
  }

}

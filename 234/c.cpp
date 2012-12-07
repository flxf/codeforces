#include <iostream>
#include <fstream>

using namespace std;

int t[100000];
int dp[100000][2];

int main() {
  ifstream fin("input.txt");

  int n;
  fin >> n;

  for (int i = 0; i < n; i++) {
    fin >> t[i];
  }
  fin.close();

  if (t[0] == 0) {
    dp[0][0] = 1;
    dp[0][1] = 1;
  } else if (t[0] < 0) {
    dp[0][0] = 0;
    dp[0][1] = 1;
  } else {
    dp[0][0] = 1;
    dp[0][1] = 1000000;
  }

  for (int i = 1; i < n; i++) {
    if (t[i] == 0) {
      dp[i][0] = dp[i-1][0] + 1;
      dp[i][1] = min(dp[i-1][0] + 1, dp[i-1][1] + 1);
    } else if (t[i] < 0) {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = min(dp[i-1][0] + 1, dp[i-1][1] + 1);
    } else {
      dp[i][0] = dp[i-1][0] + 1;
      dp[i][1] = min(dp[i-1][1], dp[i-1][0]);
    }
  }

  ofstream fout("output.txt");
  fout << dp[n-1][1] << endl;
  fout.close();
}

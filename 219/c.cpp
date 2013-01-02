#include <string>
#include <cstdio>

using namespace std;

int n, k;
char line[500001];

#define MAX_COST 1000000

int dp[500001][26];
char bt[500001][26];

int main() {
  scanf("%d %d", &n, &k);
  scanf("%s", line);

  int mn = MAX_COST;
  for (int i = 'A'; i <= 'A' + (k - 1); i++) {
    dp[n - 1][i - 'A'] = (line[n - 1] == i) ? 0 : 1;
  }

  for (int i = n - 2; i >= 0; i--) {
    int best = 'A';
    for (int j = 'A'; j <= 'A' + (k - 1); j++) {
      if (dp[i + 1][j - 'A'] < dp[i + 1][best - 'A']) {
        best = j;
      }
    }

    int second_best = (best == 'A') ? 'B' : 'A';
    for (int j = 'A'; j <= 'A' + (k - 1); j++) {
      if (j != best && dp[i + 1][j - 'A'] < dp[i + 1][second_best - 'A']) {
        second_best = j;
      }
    }

    for (int j = 'A'; j <= 'A' + (k - 1); j++) {
      int cost = (line[i] == j) ? 0 : 1;
      if (j == best) {
        cost += dp[i + 1][second_best - 'A'];
        bt[i][j - 'A'] = second_best;
      } else {
        cost += dp[i + 1][best - 'A'];
        bt[i][j - 'A'] = best;
      }
      dp[i][j - 'A'] = cost;
    }
  }

  for (int j = 'A'; j <= 'A' + (k - 1); j++) {
    mn = min(mn, dp[0][j - 'A']);
  }

  printf("%d\n", mn);

  char curr = '0';
  char next;
  for (int i = 'A'; i <= 'A' + (k - 1); i++) {
    if (dp[0][i - 'A'] == mn) {
      curr = (char)i;
      printf("%c", curr);
      curr = bt[0][i - 'A'];
      break;
    }
  }

  for (int i = 1; i < n; i++) {
    printf("%c", curr);
    curr = bt[i][curr - 'A'];
  }
  printf("\n");
}

#include <iostream>
#include <iomanip>

using namespace std;

double dp[1001][1001][2];

#define PRINCESS 0
#define DRAGON 1

// MAKE THIS BOTTOM UP

double rec(int w, int b, int player) {
  if (w == 0 && b == 0) {
    if (player == PRINCESS) {
      return 0;
    } else {
      return 1;
    }
  }
  if (b <= 0) {
    return 1;
  }
  if (w <= 0) {
    return 0;
  }

  //cout << w << ":" << b << ":" << player << endl;

  if (dp[w][b][player] >= 0) {
    return dp[w][b][player];
  }

  double win = ((double) w) / (w + b);
  double notimmed = (1 - win);
  if (player == PRINCESS) {
    win += notimmed * (1 - rec(w, b - 1, 1 - player));
  } else {
    double whitejumps = ((double) w) / (w + b - 1);
    double blackjumps = ((double) b - 1) / (w + b - 1);
    win += notimmed * (1 - (whitejumps * rec(w - 1, b - 1, 1 - player) + blackjumps * rec(w, b - 2, 1 - player)));
  }

  dp[w][b][player] = win;
  //cout << w << ":" << b << ":" << player << ":" << win << endl;
  return win;
}

int main() {
  int w, b;
  cin >> w >> b;
  for (int i = 0; i <= w; i++) {
    for (int j = 0; j <= b; j++) {
      for (int p = 0; p < 2; p++) {
        dp[i][j][p] = -1;
      }
    }
  }

  for (int i = 1; i <= w; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 0; k < 2; k++) {
        rec(i, j, k);
        //cout << "=================" << endl;
      }
    }
  }

  cout << setprecision(9) << rec(w, b, 0) << endl;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string grid[8];
int can1[8][8];
int can2[8][8];

void dfs(int r, int c, int reach[][8], int k) {
  if (r < 0 || c < 0 || r >= 8 || c >= 8) {
    return;
  }

  if (reach[r][c] != -1) {
    return;
  }
  reach[r][c] = k;
  dfs(r + 2, c + 2, reach, k + 1);
  dfs(r + 2, c - 2, reach, k + 1);
  dfs(r - 2, c + 2, reach, k + 1);
  dfs(r - 2, c - 2, reach, k + 1);
}

int main() {
  int t;
  cin >> t;

  string junk;
  getline(cin, junk);

  vector<pair<int, int> > knights;

  for (int i = 0; i < t; i++) {
    knights.clear();

    // read
    for (int r = 0; r < 8; r++) {
      getline(cin, grid[r]);
      //cout << grid[r] << endl;
    }

    getline(cin, junk);

    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        can1[r][c] = -1;
        can2[r][c] = -1;

        if (grid[r][c] == 'K') {
          knights.push_back(make_pair(r, c));
        }
      }
    }

    //cout << knights[0].first << "," << knights[0].second << endl;

    dfs(knights[0].first, knights[0].second, can1, 0);
    dfs(knights[1].first, knights[1].second, can2, 0);

    bool good = false;
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        if (can1[r][c] != -1 && can2[r][c] != -1 && can1[r][c] % 2 == can2[r][c] % 2 && grid[r][c] != '#') {
          good = true;
        }
      }
    }

    if (good) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

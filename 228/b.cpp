#include <iostream>
#include <string>

using namespace std;

int a[50][50];
int b[50][50];

int main() {
  int na, ma, nb, mb;
  cin >> na >> ma;

  string line;
  for (int i = 0; i < na; i++) {
    cin >> line;
    for (int j = 0; j < ma; j++) {
      a[i][j] = (line[j] == '1') ? 1 : 0;
    }
  }

  cin >> nb >> mb;
  for (int i = 0; i < nb; i++) {
    cin >> line;
    for (int j = 0; j < mb; j++) {
      b[i][j] = (line[j] == '1') ? 1 : 0;
    }
  }

  int bestsum = 0;
  int bestx = 0, besty = 0;
  for (int x = -50; x < 50; x++) {
    for (int y = -50; y < 50; y++) {
      int sum = 0;
      for (int i = 0; i < na; i++) {
        for (int j = 0; j < ma; j++) {
          if (x + i >= 0 && y + j >= 0 && x + i < nb && y + j < mb) {
            sum += a[i][j] * b[x + i][y + j];
          }
        }
      }

      if (sum > bestsum) {
        //cout << x << ":" << y << ":" << sum << endl;
        bestsum = sum;
        bestx = x;
        besty = y;
      }
    }
  }

  cout << bestx << " " << besty << endl;
}

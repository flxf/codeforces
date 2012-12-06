#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int n;
bool used[100];
int seats[50][2];
string s;

bool place(int cnt) {
  if (cnt == n) {
    return true;
  }

  bool ret = false;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      bool ok = false;
      if (cnt % 2 == 0) {
        ok = true;
      } else {
        int partner = seats[cnt / 2][(cnt + 1) % 2];
        if (s[partner] == 'L' || s[i] == 'R') {
          ok = (partner - i) != 1 && (i - partner) != 1;
        }
      }

      if (ok) {
        used[i] = true;
        seats[cnt / 2][cnt % 2] = i;
        ret = place(cnt + 1);
        if (ret) {
          return true;
        }
        used[i] = false;
      }
    }
  }

  return false;
}

int main() {
  ifstream fin("input.txt");

  fin >> n;
  fin >> s;
  fin.close();

  for (int i = 0; i < n; i++) {
    used[i] = false;
  }

  ofstream fout("output.txt");
  bool res = place(0);
  if (!res) {
    cout << "WTF" << endl;
  }

  for (int i = 0; i < n / 2; i++) {
    fout << seats[i][0] + 1 << " " << seats[i][1] + 1 << endl;
  }
  fout.close();
}

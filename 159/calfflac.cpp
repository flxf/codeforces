/*
ID: uncompe1
PROG: calfflac
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

char parse[20000];
//char rev[20000];
int map[20000];
string orig;


int main() {
  ifstream fin;
  fin.open("calfflac.in");

  stringstream buf;
  buf << fin.rdbuf();
  fin.close();
  orig = buf.str();
  //cout << orig << endl;

  int cnt = 0;
  for (int i = 0; i < orig.size(); i++) {
    if (orig[i] >= 'A' && orig[i] <= 'Z') {
      parse[cnt] = orig[i] - 'A' + 'a';
      //rev[cnt] = parse[cnt];
      map[cnt] = i;
      cnt++;
    } else if (orig[i] >= 'a' && orig[i] <= 'z') {
      parse[cnt] = orig[i];
      //rev[cnt] = parse[cnt];
      map[cnt] = i;
      cnt++;
    }
  }

  //reverse(rev, rev+cnt);
  //for (int i = 0; i < cnt; i++) {
    //cout << rev[i];
  //}
  //cout << endl;

  int best = 1;
  int bestx = 0;
  int besty = 0;
  int len;
  for (int i = 0; i < cnt; i++) {
    // odd length
    int j = 1;
    while (i - j >= 0 && i + j < cnt && j <= 999) {
      if (parse[i - j] != parse[i + j]) {
        break;
      }

      j++;
    }

    len = 1 + (j - 1) * 2;
    if (len > best) {
      best = len;
      bestx = i - (j - 1);
      besty = i + (j - 1);
    }

    // even length
    j = 1;
    while (i - j + 1 >= 0 && i + j < cnt && j <= 1000) {
      if (parse[i - j + 1] != parse[i + j]) {
        break;
      }

      j++;
    }

    len = (j - 1) * 2;
    if (len > best) {
      best = len;
      bestx = i - (j - 1) + 1;
      besty = i + (j - 1);
    }
  }

  ofstream fout("calfflac.out");
  fout << best << endl;
  fout << orig.substr(map[bestx], map[besty] - map[bestx] + 1) << endl;
  fout.close();
}

#include <iostream>
#include <vector>
#include <string>

#define MAX 2000000

using namespace std;

int lft[MAX];
int rgt[MAX];

int main() {
  string moves;
  cin >> moves;

  for (int i = 0; i < moves.length(); i++) {
    lft[i] = -1;
    rgt[i] = -1;
  }

  for (int p = 0; p < moves.length() - 1; p++) {
    int last = p;
    int next = p + 1;
    if (moves[p] == 'r') {
      lft[next] = last;
      rgt[next] = rgt[last];
      if (rgt[last] != -1) {
        lft[rgt[last]] = next;
      }
      rgt[last] = next;
    } else {
      rgt[next] = last;
      lft[next] = lft[last];
      if (lft[last] != -1) {
        rgt[lft[last]] = next;
      }
      lft[last] = next;
    }
  }

  int lftmost = -1;
  for (int i = 0; i < moves.length(); i++) {
    if (lft[i] == -1) {
      lftmost = i;
      break;
    }
  }

  //for (int i = 0; i < moves.length(); i++) {
    //cout << i << ": " << lft[i] << " - " << rgt[i] << endl;
  //}

  for (int i = 0; i < moves.length(); i++) {
    cout << lftmost + 1 << endl;
    lftmost = rgt[lftmost];
  }
}

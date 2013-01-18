#include <iostream>

using namespace std;

char seq[100];
char cop[100];

int cnt[10];

int main() {
  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++) {
    cin >> seq[i];
  }

  for (int i = 0; i < q; i++) {
    for (int i = 0; i < n; i++) {
      cop[i] = seq[i];
    }
    for (int i = 0; i < 10; i++) {
      cnt[i] = 0;
    }

    int l, r;
    cin >> l >> r;
    l--;
    r--;

    int cp = l;
    char dir = '>';
    char sp;
    char last = '-';
    int lp = -1;

    //cout << "ReASON" << endl;
    while (true) {
      if (cp < l || cp > r) {
        break;
      }

      //for (int i = 0; i < n; i++) {
        //cout << cop[i];
      //}
      //cout << endl;

      sp = cop[cp];
      if (sp == '-') {
        goto next;
      }

      if (sp == '<' || sp == '>') {
        dir = sp;
        if (last == '<' || last == '>') {
          cop[lp] = '-';
        }
        goto next;
      }

      if (sp == '0') {
        cnt[0]++;
        cop[cp] = '-';
      } else {
        cnt[sp - '0']++;
        cop[cp] = (sp - 1);
      }

      next:

      if (sp != '-') {
        last = sp;
        lp = cp;
      }

      if (dir == '>') {
        cp++;
      } else {
        cp--;
      }
    }

    for (int i = 0; i < 10; i++) {
      cout << cnt[i] << " ";
    }
    cout << endl;
  }
}

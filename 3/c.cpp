#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string tables[3];

char row(int i) {
  if (tables[i][0] == tables[i][1] && tables[i][1] == tables[i][2]) {
    return tables[i][0];
  }
  return '.';
}

char col(int i) {
  if (tables[0][i] == tables[1][i] && tables[1][i] == tables[2][i]) {
    return tables[0][i];
  }
  return '.';
}

char diag1() {
  if (tables[0][0] == tables[1][1] && tables[1][1] == tables[2][2]) {
    return tables[0][0];
  }
  return '.';
}

char diag2() {
  if (tables[0][2] == tables[1][1] && tables[1][1] == tables[2][0]) {
    return tables[0][2];
  }
  return '.';
}

int main() {
  for (int i = 0; i < 3; i++) {
    cin >> tables[i];
  }

  int Xes = 0;
  int Oes = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tables[i][j] == 'X') {
        Xes++;
      } else if (tables[i][j] == '0') {
        Oes++;
      }
    }
  }

  if (abs(Xes - Oes) > 1 || Oes > Xes) {
    cout << "illegal" << endl;
    return 0;
  }

  int xwins = 0;
  int owins = 0;

  char ans = row(0);
  if (ans == 'X') {
    xwins++;
  } else if (ans == '0') {
    owins++;
  }
  ans = row(1);
  if (ans == 'X') {
    xwins++;
  } else if (ans == '0') {
    owins++;
  }
  ans = row(2);
  if (ans == 'X') {
    xwins++;
  } else if (ans == '0') {
    owins++;
  }
  ans = col(0);
  if (ans == 'X') {
    xwins++;
  } else if (ans == '0') {
    owins++;
  }
  ans = col(1);
  if (ans == 'X') {
    xwins++;
  } else if (ans == '0') {
    owins++;
  }
  ans = col(2);
  if (ans == 'X') {
    xwins++;
  } else if (ans == '0') {
    owins++;
  }
  ans = diag1();
  if (ans == 'X') {
    xwins++;
  } else if (ans == '0') {
    owins++;
  }
  ans = diag2();
  if (ans == 'X') {
    xwins++;
  } else if (ans == '0') {
    owins++;
  }

  if (xwins > 0 && owins > 0) {
    cout << "illegal" << endl;
  } else if (xwins > 0) {
    if (Xes > Oes) {
      cout << "the first player won" << endl;
    } else {
      cout << "illegal" << endl;
    }
  } else if (owins > 0) {
    if (Xes == Oes) {
      cout << "the second player won" << endl;
    } else {
      cout << "illegal" << endl;
    }
  } else if (Xes + Oes == 9) {
    cout << "draw" << endl;
  } else {
    if (Xes > Oes) {
      cout << "second" << endl;
    } else {
      cout << "first" << endl;
    }
  }
}

#include <iostream>
#include <string>

using namespace std;

bool ww(char a, char b) {
  return (a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R');
}

bool ll(char a, char b) {
  return (a == 'R' && b == 'P') || (a == 'P' && b == 'S') || (a == 'S' && b == 'R');
}

int main() {
  int n;
  cin >> n;

  string a, b;
  cin >> a >> b;

  int common = a.size() * b.size();
  string A, B;
  A = "";
  B = "";

  // LOLOL ROPES.
  for (int i = 0; i < b.size(); i++) {
    A += a;
  }
  for (int i = 0; i < a.size(); i++) {
    B += b;
  }

  int win = 0, loss = 0;
  for (int i = 0; i < common; i++) {
    if (ww(A[i], B[i])) {
      win++;
    } else if (ll(A[i], B[i])) {
      loss++;
    }
  }

  int rem = n % common;
  int times = n / common;
  int winagain = 0, lossagain = 0;
  for (int i = 0; i < rem; i++) {
    if (ww(A[i], B[i])) {
      winagain++;
    } else if (ll(A[i], B[i])) {
      lossagain++;
    }
  }

  cout << loss * times + lossagain << " " << win * times + winagain << endl;
}

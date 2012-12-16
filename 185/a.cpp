#include <iostream>

using namespace std;

#define C 1000000007
#define ULL unsigned long long

ULL fastk(ULL n, int k) {
  if (n == 1) {
    return k;
  }

  ULL a = fastk(n / 2, k);
  if (n % 2 == 0) {
    return (a * a) % C;
  } else {
    return (((a * a) % C) * k) % C;
  }
}

int main() {
  ULL n;
  cin >> n;

  if (n == 0) {
    cout << 1 << endl;
    return 0;
  }

  int a = (int)(fastk(n, 4));
  int b = (int)(fastk(n, 2));

  int dividethis = (a - b + C) % C;
  //cout << dividethis << "<<<" << endl;
  if (dividethis % 2 == 0) {
    dividethis /= 2;
  } else {
    dividethis = (dividethis + C) / 2;
  }


  //cout << a << ":" << b << ":" << dividethis << endl;
  cout << (dividethis + b) % C << endl;

  //// we need fast exponentiation

  //int up = 1, down = 0;
  //int nup, ndown;
  //for (int i = 0; i < 25; i++) {
    //cout << up << ":" << down << endl;
    //nup = 3 * up + down;
    //ndown = 3 * down + up;
    //up = nup;
    //down = ndown;
  //}
}

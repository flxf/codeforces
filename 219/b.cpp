#include <iostream>
#include <vector>

using namespace std;

int main() {
  unsigned long long p, d;
  cin >> p >> d;

  unsigned long long ten = 10;
  unsigned long long best = p;
  while (true) {
    if (p < ten) {
      break;
    }
    if (p % ten == ten - 1) {
      ten *= 10;
      continue;
    }

    unsigned long long top = ((p / ten) - 1) * ten;
    unsigned long long bot = ten - 1;
    if (top + bot >= p - d) {
      best = top + bot;
    }

    ten *= 10;
  }

  cout << best << endl;
}



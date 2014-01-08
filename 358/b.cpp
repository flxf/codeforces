#include <iostream>
#include <string>

using namespace std;

char pattern[400000];

int main() {
  int n;
  cin >> n;

  int iter = 0;

  string line;
  for (int i = 0; i < n; i++) {
    cin >> line;

    pattern[iter] = '<';
    iter++;
    pattern[iter] = '3';
    iter++;
    for (int j = 0; j < line.size(); j++) {
      pattern[iter] = line[j];
      iter++;
    }
  }

  pattern[iter] = '<';
  iter++;
  pattern[iter] = '3';
  iter++;

  string target;
  cin >> target;

  int curr = 0;
  int parallel = 0;

  while (curr < iter) {

    bool found = false;
    while (parallel < target.size()) {
      if (target[parallel] == pattern[curr]) {
        found = true;
        break;
      }
      parallel++;
    }

    if (!found) {
      break;
    }

    curr++;
    parallel++;
  }

  if (curr == iter) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}

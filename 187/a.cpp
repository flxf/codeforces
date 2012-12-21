#include <iostream>

using namespace std;

int map[200001];
int seq[200001];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> seq[i];
  }

  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    map[v] = i;
  }

  for (int i = 0; i < n; i++) {
    seq[i] = map[seq[i]];
    //cout << seq[i] << " ";
  }
  //cout << endl;

  int outoforder = -1;
  for (int i = 1; i < n; i++) {
    if (seq[i] < seq[i - 1]) {
      outoforder = i;
      break;
    }
  }

  if (outoforder == -1) {
    cout << 0 << endl;
  } else {
    cout << n - outoforder << endl;
  }
}

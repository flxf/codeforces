#include <algorithm>
#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

pair<int, int> b[1000];

int main() {
  ifstream fin("input.txt");

  int n, k;
  fin >> n >> k;

  int v;
  for (int i = 0; i < n; i++) {
    fin >> v;
    b[i] = make_pair(v, i);
  }
  fin.close();

  ofstream fout("output.txt");

  sort(b, b+n);
  fout << b[n-k].first << endl;
  for (int i = n - 1; i >= n - k; i--) {
    //cout << i << ":" << b[i].first << endl;
    fout << b[i].second + 1 << " ";
  }
  fout << endl;
  fout.close();
}

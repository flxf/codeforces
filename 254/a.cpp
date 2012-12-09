#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
  ifstream fin("input.txt");

  int n;
  fin >> n;
  n *= 2;

  vector<pair<int, int > > p;
  int v;
  for (int i = 0; i < n; i++) {
    fin >> v;
    p.push_back(make_pair(v, i + 1));
  }
  sort(p.begin(), p.end());

  ofstream fout("output.txt");
  for (int i = 0; i < n; i += 2) {
    if (p[i].first != p[i + 1].first) {
      fout << -1 << endl;
      return false;
    }
  }

  for (int i = 0; i < n; i += 2) {
    fout << p[i].second << " " << p[i + 1].second << endl;
  }
  fout.close();
}

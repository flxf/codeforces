#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int dom[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int toint(int month, int day) {
  month--;
  int sum = 0;
  for (int i = 0; i < month; i++) {
    sum += dom[i];
  }
  return sum += day - 1;
}

int main() {
  ifstream fin("input.txt");

  int n;
  fin >> n;

  int m, d, p, t;
  vector<pair<int, int> > a;
  for (int i = 0; i < n; i++) {
    fin >> m >> d >> p >> t;
    int g = toint(m, d);
    a.push_back(make_pair(g - t, p));
    a.push_back(make_pair(g, -1 * p));
  }

  sort(a.begin(), a.end());
  int best = 0;
  int sum = 0;
  for (int i = 0; i < a.size(); i++) {
    sum += a[i].second;
    best = max(sum, best);
    //cout << a[i].first << ":" << a[i].second << ":" << sum << endl;
  }

  ofstream fout("output.txt");
  fout << best << endl;
  fout.close();
}
